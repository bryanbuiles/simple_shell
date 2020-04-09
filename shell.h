#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

void shell(int c, char *v[], char **env);
char *_getenv(const char *name);
int _strlen(const char *str);
char *_strcpy1(char *dest, char *src, int flag);
char *_strcat(char *dest, const char *src);
char **split_line(char *line, char *delimiter);
char *_which(char *filename);

#endif
