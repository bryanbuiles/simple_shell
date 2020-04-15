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
	/*int Ex_Status = 0;*/
	char *buffer = NULL, **args, *pathname = NULL;
	str_p buf_count;

	do

	{
		buf_count = shell_prompt(count);
		buffer = buf_count.buffer, count = buf_count.count;
		/*Ex_Status = 0;*/

		if (*buffer == '\0')
			free(buffer);
		else
		{
			args = split_line(buffer, " \t");
			if (args[0] == NULL)
				free(args);
			else
			{
				if (_strcmp(args[0], "exit") == 0)
				{
					fredom(args, buffer, pathname, 0);
					exit(0);
				}
				check = apply_builtins(args, buffer);
				if (check == 0)
					free(args);
				else
					family(args, buffer, pathname, av, count);
			}
			free(buffer);
		}
	} while (flag);

	(void)ac, (void)av, (void)env;
	return (0);
}
