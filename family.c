#include "shell.h"
/**
 * family - the fork process
 * @args: Double pointer to tokens like: {"ls","-l" NULL}
 * @buffer: It's the pointer from getline function from stdin
 * @av: argument vector or array of arguments
 * @count: The counter for every shell prompt display
 * Return: 0 if succes
 */
int family(char **args, char *buffer, char **av, int count)
{
	pid_t pid;
	int status = 0, exit_ = 0, flag = 0;
	char *pathname = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		return (1);
	}
	if (pid == 0)
	{
		pathname = _which(args[0]);
		if (pathname == NULL)
		{
			errores(args, av, count, 1);
			fredom(args, buffer, pathname, 0);
			exit(127);
		}
		if (execve(pathname, args, environ) == -1)
		{
			errores(args, av, count, 2), perror("");
			if (_strcmp(pathname, "..") == 0)
				flag = 1;
			fredom(args, buffer, pathname, 1);
			if (flag == 1)
				exit(127);
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
