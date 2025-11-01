## ⚠️ Key issues and corrections

### 1. `int i = 0;` instead of `i = 1;`

Your `av[0]` is the program name (`./microshell`), **not a command**.  
So your loop should skip it:

```c
i = 1;
```

Otherwise, it’ll try to execute your own binary as the first command again, which is not intended.

---

### 2. This line is unsafe:

```c
if (!strcmp(av[i], "|"))
	is_piped = 1;
```

If `av[i] == NULL` (end of array), this `strcmp` causes **undefined behavior** — you dereference a NULL pointer.

You must check before comparing:

```c
if (av[i] && !strcmp(av[i], "|"))
	is_piped = 1;
```

---

### 3. `cd` handling and exit behavior

When `cd` fails, you currently call `fatal_err()` which prints `"fatal\n"` and `exit(1);`.  
But `cd` failing is _not fatal_ — it should just print an error and continue, like:

```c
if (chdir(av[start + 1]) == -1)
{
	ft_putstr("error: cd: cannot change directory to ", 2);
	ft_putstr(av[start + 1], 2);
	ft_putstr("\n", 2);
}
```

and **not exit the entire shell**.

Your version makes the shell exit immediately on a wrong `cd`, which diverges from typical shell behavior.

---

### 4. Missing `close(in_fd)` inside the child after `dup2`

You do `dup2()` correctly, but if it succeeds, you should **close the original** `in_fd`, since `dup2()` creates a duplicate.  
Otherwise, your child holds an extra unused fd reference.

You can fix it by adding after the `dup2(in_fd, 0)`:

```c
if (in_fd)
	close(in_fd);
```

---

### 5. `execve()` and PATH resolution

You only do `execve(av[start], &av[start], env)` — this will fail unless the user provides full paths (`/bin/ls`, not `ls`).  
That’s okay for a basic exercise (like the 42 microshell project), but worth noting — real shells use `execvp()` or implement PATH lookup.

---

### 6. Error messages: too generic

Your fatal errors just print `"fatal\n"`.  
That’s fine internally, but it’s much more helpful to follow the format:

```
error: fatal
```

and also, non-fatal messages (like command-not-found) should not use `fatal_err()` — should continue gracefully.

### 1. Missing `close()` calls in child after successful `dup2`

After duplicating with `dup2(in_fd, 0)` or `dup2(p[1], 1)`,  
you should **close** the original descriptors — they’re duplicated now and not needed in the child.

Example (inside the child):

```c
if (in_fd) {
    if (dup2(in_fd, 0) < 0)
        fatal_err();
    close(in_fd); // ← missing here
}
if (is_piped) {
    if (dup2(p[1], 1) < 0)
        fatal_err();
    close(p[1]);  // ← missing here
    close(p[0]);  // ← good practice to close read end too
}
```

### 2. `execve` error handling

You call `fatal_err()` on failure. That’s too generic — it prints just `"fatal\n"`.  
The specification typically expects an error like `"error: cannot execute mycmd\n"`.

You could do:

```c
ft_putstr("error: cannot execute ", 2);
ft_putstr(av[start], 2);
ft_putstr("\n", 2);
exit(1);
```

This matches the expected microshell behavior and ensures user-level feedback rather than silent fatal exit.

---

### 3. `cd` error handling flow

Currently, on a bad `cd` you call `exit(1)`, which **kills the entire microshell** — that’s wrong.  
`cd` should fail gracefully (print an error) and continue executing later commands.

Fix:

```c
if (i - start != 2)
    ft_putstr("error: cd wrong args\n", 2);
else if (chdir(av[start + 1]) == -1)
    ft_putstr("error: cd cannot cd to dir\n", 2);
continue; // do NOT exit
```

---

### 4. `fatal_err()` message

"fatal\n" is not descriptive enough and doesn’t include a newline style or cause info.  
Conventionally, use `"error: fatal\n"`.

---

### 5. Minor: missing closing `close(p[1])` / `close(p[0])` hygiene

You already close them properly in parent, but to be extra safe and match the original behavior, ensure both sides close unneeded ends in the child and parent paths consistently.
