## Simple SHell

### Description:

- We create our own simple UNIX command interpreter. The program has the same output as /bin/sh.

### Instructions:

Compiling the program with: gcc -Wall -Werror -Wextra -pedantic \*.c -o shell

In interactive mode:

Non-interactive mode:

### Files:

| File        | Description       |
| ----------- | ----------------- |
| shell.c     | Execute the shell |
| shell.h     | Header            |
| functions.c | Helper functions  |
| \_which.c   | Find PATH         |

### Example:

    #include "holberton.h"
                  int main(void)
                    {
                    _printf("%s\n", "HELLO, HOLBERTON");
                    return (0;)
                    }

### Compilation:

`$ gcc -Wall -Werror -Wextra -pedantic *.c -o shell`

### Authors:

| Authors                 | Email                    |
| ----------------------- | ------------------------ |
| Bryan Builes Echavarria | 1482@holbertonschool.com |
| Erika osorio Guerrero   | 1476@holbertonschool.com |
