# get_next_line

A compact, norm-compliant implementation of the get_next_line project (42 school) in C.

get_next_line reads a file descriptor line by line, returning each line (including the terminating newline `\n` when present) as a heap-allocated string. This repository includes the mandatory part and common optional/better-practice features (see "Features" below). The implementation is safe to use with different buffer sizes through the `BUFFER_SIZE` macro.

---

## Table of contents

- [Features](#features)
- [Behavior](#behavior)
- [Function prototype](#function-prototype)
- [Usage and compilation](#usage-and-compilation)
- [Example](#example)
- [Testing and debugging tips](#testing-and-debugging-tips)
- [Implementation notes](#implementation-notes)
- [Contributing](#contributing)
- [License](#license)
- [Author](#author)

---

## Features

- Reads from any file descriptor (stdin, files, sockets, ...).
- Returns one line per call, allocated with `malloc`.
- Works with a configurable `BUFFER_SIZE` macro.
- Designed to respect 42 project norms (no forbidden functions used).
- Handles end-of-file and returns `NULL` on error or when there are no more lines.

(The repository contains a bonus version that supports multiple simultaneous file descriptors, that behavior is documented and implemented as well — check the source for `bonus` or `get_next_line_bonus` variants.)

---

## Behavior

- On success: returns a pointer to a null-terminated string containing the next line read from `fd`. The returned string includes the newline character if one was encountered before EOF.
- On EOF with no bytes read: returns `NULL`.
- On error: returns `NULL` (and frees any allocated resources internally).
- The caller is responsible for freeing the returned string to avoid memory leaks.

---

## Function prototype

Mandatory:
```c
char *get_next_line(int fd);
```

Bonus:
```c
char *get_next_line_bonus(int fd);
```

Set `BUFFER_SIZE` at compile time or in a header (for example `-DBUFFER_SIZE=32`). Testing with different sizes is recommended.

---

## Example

Simple usage in a program:
```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd < 0)
        return 1;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

---

## Testing and debugging tips

- Use `valgrind` to check for leaks:
  ```bash
  valgrind --leak-check=full ./gnl_test
  ```
- Test with different `BUFFER_SIZE` values:
  ```bash
  gcc -D BUFFER_SIZE=1 ...
  gcc -D BUFFER_SIZE=4096 ...
  ```
- Test with multiple file descriptors (if bonus): open multiple files and alternate calls to `get_next_line(fd1)` and `get_next_line(fd2)`.

---

## Implementation notes

- Only allowed functions: `read`, `malloc`, `free` (and functions from `<unistd.h>`, `<stdlib.h>`, `<stddef.h>`, `<limits.h>`, etc. as required).
- The code is organized into source and header files (check `src/` and `includes/`).
- Edge cases handled: empty files, files without trailing newline, very long lines that exceed `BUFFER_SIZE`, and partial reads.

---

## Contributing

Contributions, bug reports, and improvements are welcome. Please open an issue describing the change or create a pull request. If you add tests, include clear instructions to run them.

---

## License

This project is provided under the MIT License. See LICENSE file for details (or add one if not present).

---

## Author

Adnilson Pinheiro — https://github.com/AdnilsonPinheiro
