#include "shell.h"
/**
 * apply_builtins - function that search and aply builtins
 * @args: Array of pointers (token)
 * @line: String from prompt
 * Return: 0 if find at coicidence or 1 if not
 */
int apply_builtins(char **args, char *line)
{
	int i;

	builtins_t all[] = {
		/* {"exit", shellexit}, */
		{"env", envshell},
		{NULL, NULL}};
	for (i = 0; all[i].arg != NULL; i++)
	{
		if (_strcmp(all[i].arg, args[0]) == 0)
		{
			all[i].f(args, line);
			return (0);
		}
	}
	return (1);
}
/**
 * envshell - function that prints the environ
 * @args: Array of pointers (token)
 * @line: String from prompt
 * Return: void
 */
void envshell(char **args, char *line)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _strlen(environ[i]));
		write(1, "\n", 1);
	}
	(void)args;
	(void)line;
}
