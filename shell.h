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
#include <signal.h> 

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
int _strcmp(const char *s1, const char *s2);

void shellexit(char **args, char *line);
int apply_builtins(char **args, char *line);
void envshell(char **args, char *line);
void ignore_signal(int signal __attribute__((unused)));
void errores(char **args, char **av, int count, int error);
char *_itoa(int num);
int _numlen(int n);

str_p shell_prompt(int count, int exit_);
void fredom(char **args, char *buffer, char *pathname, int flag);
int family(char *pathname, char **args);
int access_to_family(char **args, char **av, int count);



char *_find_exe_cwd(char *filename);
char *find_slash(char *filename);
char *PATH_empty(char *filename);
char *find_exe_Path(char *filename, int index, char *newpath);

char *_strchr(char *s, char c);
void _setenv(char **args, char *line);
int cwd_inside_PATH(char *fullpathname);
char *_strtok(char *str, const char *delim);

#endif
