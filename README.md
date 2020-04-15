# Simple Shell

The simple shell is a command-line interpreter or shell that provides a command line user interface for Unix-like operating systems.

## Description:

We create our own simple UNIX command interpreter. The program has the same output as /bin/sh as well as the exact same error output. The only difference is when you print an error, the name of the program must be equivalent to your argv[0].

## Features

- Includes exit function that exits the shell
- Includes enviroment builtin that display the current enviroment
- Display a prompt where the user can type a command
- Can handle commands with arguments
- Use the PATH variable to find and execute the command

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

## Usage

1. Type ./shell in your shell. You should be promped with a \$.
2. Type a command and press "Enter".
3. An ouput will appear.
4. Type your next command if you want.
5. Exit shell by typing "exit"

### Blog:

https://medium.com/@erikaosgue/4a72ef258c3a

## Files:

This repository contains the following files:

| File               | Description          |
| ------------------ | -------------------  |
| shell.c            | Execute the shell    |
| shell.h            | Header               |
| functions.c        | Helper functions     |
| \_which.c          | Find PATH            |
| \_getenv.c         | Find env variable    |
| builtins.c         | Builtins functions   |
| helper_functions.c | Helper functions2    |
| fredom.c           | free pointers        |
| family.c           | fork() sys call      |
| \_itoa.c           | convert a int to str |
| shell_prompt.c     | Display prompt       |

## Authors:

| Authors                 | Email                    |
| ----------------------- | ------------------------ |
| Bryan Builes Echavarria | 1482@holbertonschool.com |
| Erika Osorio Guerrero   | 1476@holbertonschool.com |
