#include "shell.h"

/**
 * family - the fork process
 * @args: Double pointer to tokens like: {"ls","-l" NULL}
 * @buffer: It's the pointer from getline function from stdin
 * @pathname: it's the first argument of args -> args[0]
 * @av: argument vector or array of arguments
 * @count: The counter for every shell prompt display
 * Return: 0 if succes
 */
int family(char **args, char *buffer, char **av, int count)
{
	pid_t pid;
	int Ex_Status = 0, status;
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
			free(args);
			free(buffer);
			exit(127);
		}
		if (execve(pathname, args, environ) == -1)
		{
			errores(args, av, count, 2);
			free(pathname);
			free(args);
			free(buffer);
			perror("");
			exit (127);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		Ex_Status = WEXITSTATUS(status);
	}
	free(pathname);
	return(0);

}
