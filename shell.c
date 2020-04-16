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
	int flag = 1, check, count = 0, exit_ = 0;
	char *buffer = NULL, **args;
	str_p buf_count;

	do

	{
		buf_count = shell_prompt(count, exit_);
		buffer = buf_count.buffer;
		count = buf_count.count;
		exit_ = 0;

		if (*buffer != '\0')
		{
			args = split_line(buffer, " \t\r\a");
			if (args[0] != NULL)
			{
				check = apply_builtins(args, buffer);
				if (check != 0)
					exit_ = family(args, buffer, av, count);
			}
			free(args);
		}
		free(buffer);
	} while (flag);

	(void)ac, (void)av, (void)env;
	return (exit_);
}
