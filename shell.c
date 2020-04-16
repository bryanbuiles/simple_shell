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
	int flag = 1, check, count = 0;
	char *buffer = NULL, **args;
	str_p buf_count;

	do

	{
		buf_count = shell_prompt(count);
		buffer = buf_count.buffer;
		count = buf_count.count;

		if (*buffer != '\0')
		{
			args = split_line(buffer, " \t\r\a");
			if (args[0] != NULL)
			{
				if (_strcmp(args[0], "exit") == 0)
				{
					/*fredom(args, buffer, pathname, 0); */
					free(args);
					free(buffer);
					exit(0);
				}
				check = apply_builtins(args, buffer);
				if (check != 0)
				{
					family(args, buffer, av, count);
				}
			}
			free(args);
		}
		free(buffer);
	} while (flag);

	(void)ac, (void)av, (void)env;
	return (0);
}
