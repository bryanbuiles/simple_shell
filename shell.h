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
#include <limits.h>

#define PATH_MAX 4096

/**
 * struct builtins - struct that search for the builtin
 * @arg: Builtin name
 * @f: pointer to functions.
 */

typedef struct builtins
{
	char *arg;
	void (*f)(char **args, char *line);
} builtins_t;

/**
 * struct prompt - struct that bring buffer and count to shell
 * @buffer: It's the pointer from getline function from stdin
 * @count: The counter for every shell prompt display
 */

typedef struct prompt
{
	char *buffer;
	int count;
} str_p;

extern char **environ;
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
void ignore_signal(int signal __attribute__((unused)));
void errores(char **args, char **av, int count, int error);
char *_itoa(int num);
int _numlen(int n);

str_p shell_prompt(int count);
void fredom(char **args, char *buffer, char *pathname, int flag);
int family(char **args, char *buffer, char *pathname, char **av, int count);

#endif
