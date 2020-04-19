#include "shell.h"
/**
 * access_to_family - the fork process
 * @args: Double pointer to tokens like: {"ls","-l" NULL}
 * @buffer: It's the pointer from getline function from stdin
 * @av: argument vector or array of arguments
 * @count: The counter for every shell prompt display
 * Return: 0 if succes, other number otherwise
 */
int access_to_family(char **args, char *buffer, char **av, int count)
{
	char *pathname = NULL;

	if (_strcmp(args[0], "..") == 0)
	{
		errores(args, av, count, 3);
		return (127);
	}
	pathname = _which(args[0]);
	if (pathname == NULL)
	{
		errores(args, av, count, 1);
		return (127);
	}
	if (access(pathname, X_OK) != 0)
	{
		errores(args, av, count, 3);
		free(pathname);
		return (126);
	}
	return (family(pathname, args, buffer, av, count));
}
/**
 * family - the fork process
 * @pathname: It's the pointer to the pathname of the file
 * @args: Double pointer to tokens like: {"ls","-l" NULL}
 * @buffer: It's the pointer from getline function from stdin
 * @av: argument vector or array of arguments
 * @count: The counter for every shell prompt display
 * Return: 0 if succes, other number otherwise
 */
int family(char *pathname, char **args, char *buffer, char **av, int count)
{
	pid_t pid;
	int status = 0, exit_ = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid == 0)
	{
		if (execve(pathname, args, environ) == -1)
		{
			errores(args, av, count, 3);
			fredom(args, buffer, pathname, 1);
			exit(126);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		exit_ = (WEXITSTATUS(status));
	}
	free(pathname);
	return (exit_);
}
