#include "shell.h"
/* holaaa */
/**
 * family - the fork process
 * @args: Double pointer to tokens like: {"ls","-l" NULL}
 * @buffer: It's the pointer from getline function from stdin
 * @pathname: it's the first argument of args -> args[0]
 * @av: argument vector or array of arguments
 * @count: The counter for every shell prompt display
 * Return: 0 if succes
 */
int family(char **args, char *buffer, char *pathname, char **av, int count)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error:");
		fredom(args, buffer, pathname, 0);
		exit(0);
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
			fredom(args, buffer, pathname, 1);
			exit(0);
		}
	}
	else
	{
		do

		{
			waitpid(pid, &status, WUNTRACED);
		} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
		/*Ex_Status = WEXITSTATUS(status);*/
	}
	free(args);
	return (1);
}
