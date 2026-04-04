_This project has been created as part of the 42 curriculum by alebedev._

# get_next_line

## Description

`get_next_line` is a C function that reads and returns one line at a time from a file descriptor. Each successive call returns the next line. It is used to iterate through any text source line by line.

Beyond the utility of the function itself, the project's learning objective is understanding static variables in C: how they persist across function calls, and how that persistence can be used to maintain state — here, a leftover buffer `stash`.

## Algorithm

The implementation uses a **read-and-stash** approach:

1. Stash initialization: On the first call (or after the stash was cleared), an empty stash is allocated.
2. Early exit: If the stash already contains a `\n` from a previous over-read, skip straight to extraction.
3. Read loop: `read()` fills a stack buffer of `BUFFER_SIZE` bytes. Each chunk is appended to the stash via `ft_strjoin_free`, which frees the old stash and returns a fresh allocation. This continues until a `\n` is found or EOF is reached.
4. Line extraction: `extract_line` copies from the start of the stash up to and including the first `\n` (or to `\0` if none) into a new heap string.
5. Stash update: `update_stash` trims everything up to and including the consumed `\n`, keeping only the remainder for the next call. If nothing remains, the stash is freed and set to `NULL`.

**Why this approach?**

- Reading in chunks of `BUFFER_SIZE` minimises syscall overhead while staying correct at any buffer size (1, 9999, or 10 000 000).
- Freeing the old stash on every join keeps memory usage proportional to content, not to the number of calls.
- The stash pointer is the sole static variable — satisfying both the mandatory and bonus requirements.

The bonus variant replaces the single `char *stash` with `char *stashes[FD_SETSIZE]`, indexed by `fd`, enabling independent tracking of multiple file descriptors with no other structural change.

## Instructions

### Compilation

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Compile without a custom buffer size (uses the default of 1000):

```bash
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c
```

Bonus (multiple file descriptor support):

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c
```

### Usage

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int   fd;
    char *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
}
```

## Resources

- read man page
- open man page

### AI usage

Claude helped me pinpoint algorithmic complexity bottleneck (using strlen in each read)
