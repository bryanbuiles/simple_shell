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

typedef struct builtins
{
    char *arg;
    void (*f)(char **args, char *line);
} builtins_t;

void shell(int c, char *v[], char **env);
char *_getenv(const char *name);
int _strlen(const char *str);
char *_strcpy1(char *dest, char *src, int flag);
char *_strcat(char *dest, const char *src);
char **split_line(char *line, char *delimiter);
char *_which(char *filename);
char *_strstr(char *haystack, char *needle);
char *_strdup(char *str);
int errorMj(char *message[], int count);
int _putchar(char c);
int _strcmp(char *s1, char *s2);

void shellexit(char **args, char *line);
int apply_builtins(char **args, char *line);
void envshell(char **args, char *line);
#endif
