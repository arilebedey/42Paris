### Intro

`fork()` effectively returns in two places simultaneously: once in the parent process (returning the child's PID) and once in the child process (returning 0). This happens because `fork()` creates a new process by duplicating the calling process, and both processes continue execution from the point of the `fork()` call with their respective return values.

Checking if `fork()` returns 0 is the standard and primary way to identify the child process. The child process always receives 0 from `fork()`, while the parent receives the child's PID or -1 on error.

If we see 0 as the return value of `fork()`, we know we are in the child process.
If we see a PID, we know we are in the parent.

We should also note that the child process inherits the parent’s instruction pointer (or program counter).

### Orphaned processes

It is then adopted by `init` (its PPID becomes 1).

### The Wait and Waitpid System Calls

In order to suspend the parent process’ execution until the child process’ state changes, we can use the `wait` or `waitpid` system calls from the `<sys/wait.h>` library. Their prototypes are:

```c
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options);
```

`wait()` pauses until any child process ends, returning the first one that does. `waitpid()` pauses for a specific child (by PID), ignoring others until that child terminates. With multiple children, `wait()` grabs the first to finish, while `waitpid()` waits for the exact child you specify.

`waitpid()` offers several options. Among those, the sometimes very useful `WNOHANG`. With the `WNOHANG` option, `waitpid` returns immediately if the child process has not ended yet. Without this option, the parent process will by default remain suspended as long as the child is still executing its tasks.

Alternatively, we can specify -1 in order to wait for whichever child finished first, just like `wait` (indeed, `waitpid(-1, status, 0)` is exactly the same as `wait(status)`).

`WNOHANG`: `waitpid()` can get a child's status, but without `WNOHANG`, it blocks until the child finishes. `WNOHANG` isn't default because blocking is often desired for simpler, sequential parent-child coordination, ensuring the parent waits for child completion before proceeding. Non-blocking (`WNOHANG`) suits complex scenarios needing concurrent tasks, but it's less common, so not default.

If the system call succeeds, both `wait` and `waitpid` return the terminated child’s PID, otherwise, they return -1.

The status is an integer that represents not only the exit code but also further details that explain why a child exited.

The `waitpid` function can also return 0 if the `WNOHANG` option was specified and if the child it is waiting for has not changed states yet.

### Analyzing a Child Process’ Exit Status

`WIFEXITED(status)`: returns true if the child terminated normally, for example by calling `exit` or finishing through the `main` function of the program.

`WEXITSTATUS(status)`: to be used only if `WIFEXITED` returned true. Returns the child’s exit code, meaning the number the child specified to the `exit` function or in the `main` function’s return.

`WIFSIGNALED(status)`: returns true if the child was forcefully terminated by a signal.

`WTERMSIG(status)`: to be used only if `WIFSIGNALED` returned true. Returns the signal number that provoked the child’s termination.

### Kill: Terminating Child Processes

```c
int kill(pid_t pid, int sig);
```

The `kill()` params:

- `pid`: the PID of the process that we want to kill.
- `sig`: the signal that we want to send to the process in order to kill it. There are many different possible signals for `kill`, each with its own nuances (see `man 7 signal`), but the most frequently used are perhaps `SIGTERM` (soft termination signal) and `SIGKILL` (hard kill signal).

If we kill our child processes with a signal, we should beware of which signal we choose: `SIGTERM`, `SIGINT`, and `SIGKILL` don’t all have the same implications as far as memory leaks are concerned!

Debugging a program that creates child processes can be pretty overwhelming. `Valgrind` offers the option to mute the errors coming from child processes: `--child-silent-after-fork=yes`

### `access()`

https://42-cursus.gitbook.io/guide/2-rank-02/pipex/functions-used#access

```c
int access(const char *pathname, int mode);
```

The `mode` specifies the accessibility check(s) to be performed, and is either the value `F_OK`, or a mask consisting of the bitwise OR of one or more of `R_OK`, `W_OK`, and `X_OK`. `F_OK` tests for the existence of the file. `R_OK`, `W_OK`, and `X_OK` test whether the file exists and grants read, write, and execute permissions, respectively.

On success (all requested permissions granted), zero is returned. On error (at least one bit in `mode` asked for a permission that is denied, or some other error occurred), -1 is returned, and `errno` is set appropriately.

### `dup2()`

```c
int dup2(int oldfd, int newfd);
```

`dup2()` makes `newfd` a copy of `oldfd`, closing `newfd` first if necessary. Note:

- If `oldfd` is not a valid file descriptor, the call fails, and `newfd` is not closed.
- If `oldfd` is valid and `newfd` equals `oldfd`, `dup2()` does nothing and returns `newfd`.

On success, `oldfd` and `newfd` refer to the same open file descriptor, sharing file offset and status flags (e.g., modifying the offset with `lseek()` on one affects the other).

On success, `newfd` is returned. On error, -1 is returned, and `errno` is set appropriately.

```c
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char *av[], char *env[])
{
    (void) ac;
    (void) av;
    int in;
    int out;
    char *grep_args[] = {"grep", "Lausanne", NULL};

    // open input and output files (assuming both files exist)
    in = open("in", O_RDONLY);

    // replace standard input with input file
    dup2(in, 0);
    // close unused file descriptors
    close(in);

    // execute grep
    execve("grep", grep_args, env);
}
```

It makes file descriptor 0 a duplicate of in. This means that from this point onwards, any operations that would normally read from standard input (file descriptor 0) will now read from the file associated with in (which is your "in" file).

### `pipe()`

```c
int pipe(int pipefd[2]);
```

The `pipe()` function creates a unidirectional data channel (a pipe) for interprocess communication. It returns two file descriptors in the `pipefd` array:

- `pipefd[0]`: Read end of the pipe.
- `pipefd[1]`: Write end of the pipe.

Data written to `pipefd[1]` is buffered by the kernel until read from `pipefd[0]`.

```c
/**
 * Executes the command "cat infile | grep Lausanne".
 */

#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int ac, char *av[], char *env[])
{
    (void) ac;
    (void) av;
    int pipefd[2];
    int pid;

    char *cat_args[] = {"/bin/cat", "infile", NULL};
    char *grep_args[] = {"/usr/bin/grep", "Lausanne", NULL};

    // make a pipe
    // fds go in pipefd[0] and pipefd[1]
    pipe(pipefd);

    if (pid == 0)
    {
        // child process gets here and handles "grep Lausanne"
        // replace standard input with input part of the pipe
        dup2(pipefd[0], 0);

        // close unused half of the pipe
        close(pipefd[1]);

        // execute grep
        execve("/usr/bin/grep", grep_args, env);
    }
    else
    {
        // parent process gets here and handles "cat scores"
        // replace standard output with output part of pipe
        dup2(pipefd[1], 1);

        // close unused half of the pipe
        close(pipefd[0]);

        // execute cat
        execve("/bin/cat", cat_args, env);
    }
    // close unused pipe
    close(pipefd[0]);
    close(pipefd[1]);

    // wait for the child process to finish
    waitpid(pid);
}
```

### `execve()`

```c
int execve(const char *filename, char *const argv[], char *const envp[]);
```

execve() executes the program pointed to by filename.

On success, execve() does not return; the calling process is replaced by the new program specified by filename.

### `unlink()`

```c
int unlink(const char *pathname);
```

`unlink()` removes a specified file name from the file system.

- If the name was the last link to a file and no processes have the file open, the file is deleted, and its space is freed for reuse.
- If the name was the last link but the file is still open by any process, the file persists until all file descriptors referencing it are closed.

Returns 0 on success, or -1 on error, with `errno` set accordingly.
