#include "shell.h"
/**
 * fredom - free the pointers
 * @args: Double pointer to tokens like: {"ls","-l" NULL}
 * @buffer: It's the pointer from getline function from stdin
 * @pathname: it's the first argument of args -> args[0]
 * @flag: Signal to free specific pointers
 * Return: Nothing
 */
void fredom(char **args, char *buffer, char *pathname, int flag)
{
	if (flag == 1)
	{
		free(pathname);
	}
	if (flag != 2)
	{
		free(args);
		free(buffer);
	}
}
