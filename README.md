# Simple SHell

The simple shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems.

## Description:

We create our own simple UNIX command interpreter. The program has the same output as /bin/sh as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0].

## Instructions:

### How to dowloaded

Use directly this link:

https://github.com/erikaosgue/simple_shell.git

Go to you terminal and type

    git clone [link you just copied]

then you will have the repository in your computer

Once you do that you can use this main template and fallow the instructions for compilation

### Compilation and running

Compiling the program with:

    gcc -Wall -Werror -Wextra -pedantic *.c -o shell

Run:

In interactive mode:

     $ ./shell
      ($) ls
      functions.c README.md shell.c
      _getenv.c shell shell.h _which
      ($) exit
     $

Non-interactive mode:

     $ echo "ls" | ./shell
      functions.c README.md shell.c
      _getenv.c shell shell.h _which
     $

You can open a man page and get more information about it.

     user@ubuntu:~/c/printf$ **man ./man_1_simple_shell**

### Blog:

## Files:

| File        | Description       |
| ----------- | ----------------- |
| shell.c     | Execute the shell |
| shell.h     | Header            |
| functions.c | Helper functions  |
| \_which.c   | Find PATH         |
| \_getenv.c  | Find env variable |

## Authors:

| Authors                 | Email                    |
| ----------------------- | ------------------------ |
| Bryan Builes Echavarria | 1482@holbertonschool.com |
| Erika Osorio Guerrero   | 1476@holbertonschool.com |
