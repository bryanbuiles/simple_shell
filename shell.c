#include "shell.h"
/**
 * main - execve example
 *
 * Return: Always 0.
 */
int main(int c, char *v[], char **env)
{
	size_t bufersize = 0;
	int status, len, flag = 1, bytes;
	pid_t pid;
	char *buffer = NULL, **args;
	int check;
	//char **env = {NULL};

	do
	{
		/* isatty helps us with interactive and non inte. mode */
		/* tests whether fd is an open file descriptor referring to a terminal. */
		// if isatty return 1 is open from the terminal --> ./shell
		// if issaty return 0 was using pipe line ---> echo "/bin/ls" | ./shell
		if (isatty(STDIN_FILENO))
			write(1, "$ ", 3);

		// getline return the number of characteres it read
		// getline return -1 on failure, or end of File ctrl D
		bytes = getline(&buffer, &bufersize, stdin);
		if (bytes == EOF)
		{
			if (isatty(STDIN_FILENO))
				write(1, "\n", 1);
			free(buffer);
			exit(0);
		}

		len = _strlen(buffer);
		if (buffer[len - 1] == '\n')
			buffer[len - 1] = 0;

		// fork will start a new child proccess
		if ((pid = fork()) == -1)
		{
			perror("Error:");
			free(buffer);
			return (1);
		}
		// if pid == -0 will be the child
		if (pid == 0)
		{
			// split_line will make tokens delim. for space
			// return a double pointer, of tokens
			// we need to free just the big pointer -> free(args)
			args = split_line(buffer, " ");
			if (args == NULL)
			{
				free(buffer);
				return (1);
			}
			check = ver_builtins(args[0]);
			if (check == 1)
			{
				apply_builtins(args, buffer);
			}
			if (check == 2)
			{
				//_which will look for files in the current PATH.
				// which return a single pointer -> will be the path ej:(/bin/ls)
				//we need to free the single pointer --> free(args[0]
				args[0] = _which(args[0]);
				if (args[0] == NULL)
				{
					free(args);
					free(buffer);
					return (1);
				}

				if (execve(args[0], args, NULL) == -1)
				{
					//write(1, "./shell: ", 8);
					free(args[0]);
					free(args);
					free(buffer);
					return (1);
				}
				/* despues de execve nada funciona */
			}
		}
		//will be the parent proccess
		else
		{
			waitpid(pid, &status, 0);
		}
		//need to figure what happen when we do not use this free
		// free(args[0]);/* proviene del which */
		// free(args); /* proviene del split line */
		// free(buffer);
	} while (flag);

	if (!c)
		(void)c;
	if (v == NULL)
		(void)v;
	if (env == NULL)
		(void)env;
	free(buffer);
	return (0);
}
