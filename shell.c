#include "shell.h"
/**
 * main - This is a simple UNIX command interpreter
 * @ac:  The number of strings pointed to by av
 * @av: argument vector or array of arguments
 * @env: enviroment list
 * Return: Always 0.
 */
int main(int ac, char *av[], char **env)
{
	size_t bufersize = 0;
	int status, len, flag = 1, bytes, count = 0, check;
	pid_t pid;
	char *buffer = NULL, **args, *pathname;

	do
	{
		/* isatty helps us with interactive and non inte. mode */
		/* tests whether fd is an open file descriptor referring to a terminal. */
		// if isatty return 1 is open from the terminal --> ./shell
		// if issaty return 0 was using pipe line ---> echo "/bin/ls" | ./shell
		signal(SIGINT, ignore_signal);
		if (isatty(STDIN_FILENO))
		{
			count++;
			write(1, "GreatTeam $ ", 13);
		}
		else
		{
			//helps us counting a line in none interactive mode
			count++;
		}
		// getline return the number of characteres it read
		// getline return -1 on failure, or end of File ctrl D
		// getline allcate memory in the buffer, need to be free
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
			buffer[len - 1] = '\0';

		if (*buffer == '\0')
		{
		}
		else
		{
			// split_line will make tokens delim. for space
			// return a double pointer, of tokens
			// we need to free just the big pointer -> free(args)
			args = split_line(buffer, " \t");

			/* for (count = 0; count < 63; count++)
				printf(">>>>args[%i] = [%s]\n", count, args[count]); */
			if (args[0] == NULL)
			{
				free(args);
			}
			else
			{
				//char *message[] = {av[0], args[0], NULL};

				if (_strcmp(args[0], "exit") == 0)
				{
					free(args);
					free(buffer);
					exit(0);
				}
				check = apply_builtins(args, buffer);
				if (check == 0)
					free(args);
				else
				{
					// fork will start a new child proccess
					if ((pid = fork()) == -1)
					{
						perror("Error:");
						free(args);
						free(buffer);
						return (1);
					}
					// if pid == -0 will be the child
					if (pid == 0)
					{
						//_which will look for files in the current PATH.
						// which return a single pointer -> will be the path ej:(/bin/ls)
						//we need to free the single pointer --> free(pathname)
						pathname = _which(args[0]);
						if (pathname == NULL)
						{
							/* this is for printing and error messages */
							//errorMj(message, count);
							errores(args, av, count, 1);

							free(args);
							free(buffer);
							exit(127);
						}
						if (execve(pathname, args, env) == -1)
						{
							//write(1, "./shell: ", 8);
							free(pathname);
							free(args);
							free(buffer);
							return (1);
						}
						/* despues de execve nada funciona */
					}
					//will be the parent proccess
					else
					{
						waitpid(pid, &status, 0);
						// ret = 7
						// return (ret);
					}
					//need to figure what happen when we do not use this free
					free(args);
				}
			}
		}
	} while (flag);
	if (!ac)
		(void)ac;
	if (av == NULL)
		(void)av;
	if (env == NULL)
		(void)env;
	return (0);
}
