#include "shell.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */

int main(int c, char *v[], char **env)
{
	size_t bufersize = 0;
	int status, len, flag = 1;
	pid_t pid;
	char *buffer = NULL;
	char **args;

	do
	{
		if (isatty(STDIN_FILENO))
		{
			write(1, "$ ", 2);
		}
		getline(&buffer, &bufersize, stdin);
		{
			len = _strlen(buffer);
			if (buffer[len - 1] == '\n')
				buffer[len - 1] = 0;
			if ((pid = fork()) == -1)
			{
				perror("Error:");
				free(buffer);
				return (1);
			}
			if (pid == 0)
			{
				args = split_line(buffer, " ");
				args[0] = _which(args[0]);
				//v[0] = strtok(buffer, " ");
				if (execve(args[0], args, env) == -1)
				{
					perror("Error:");
					free(args);
					return (1);
				}
			}
			else
			{
				waitpid(pid, &status, 0);
			}
		}

	} while (flag);
	if (!c)
		(void)c;
	if (v == NULL)
		(void)v;
	if (env == NULL)
		(void)env;
	return (0);
}
