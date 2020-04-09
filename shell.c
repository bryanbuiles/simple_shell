#include "shell.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */
//int main(int c, char *v[], char **env)
int main(void)
{
	size_t bufersize = 0;
	int status, len, flag = 1;
	pid_t pid;
	char *buffer = NULL;
	char **args;
	int temp;

	do
	{
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 2);
		temp = getline(&buffer, &bufersize, stdin);
		if (temp == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			exit(0);
		}
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
			if (execve(args[0], args, NULL) == -1)
			{
				write(1, "./shell: ", 8);
				free(args);
				return (1);
			}
			free(args);
		}
		else
		{
			waitpid(pid, &status, 0);
		}
	} while (flag);

	/* if (!c)
		(void)c;
	if (v == NULL)
		(void)v;
	if (env == NULL)
		(void)env; */
	return (0);
}
