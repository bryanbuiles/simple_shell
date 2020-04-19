#include "shell.h"
/**
 * access_to_family - the fork process
 * @args: Double pointer to tokens like: {"ls","-l" NULL}
 * @av: argument vector or array of arguments
 * @count: The counter for every shell prompt display
 * Return: 0 if succes, other number otherwise
 */
int access_to_family(char **args, char **av, int count)
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
	/* checks whether the calling process can access the file pathname. succes 0*/
	if (access(pathname, X_OK) != 0)
	{
		errores(args, av, count, 3);
		free(pathname);
		return (126);
	}
	return (family(pathname, args));
}
/**
 * family - the fork process
 * @args: Double pointer to tokens like: {"ls","-l" NULL}
 * @pathname: It's the pointer to the pathname of the file
 * Return: 0 if succes
 */
int family(char *pathname, char **args)
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
		execve(pathname, args, environ);
	else
	{
		waitpid(pid, &status, 0);
		exit_ = (WEXITSTATUS(status));
	}
	free(pathname);
	return (exit_);
}
