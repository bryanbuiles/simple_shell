#include "shell.h"

void errores(char **args, char **av, int count, int error)
{

	char *str;

	str = _itoa(count);
	if (error == 1)
	{
		write(1, av[0], _strlen(av[0]));
		write(1, ": ", 2);
		write(1, str, _strlen(str));
		write(1, ": ", 2);
		write(1, args[0], _strlen(args[0]));
		write(1, ": not found\n", 13);
	}
	free(str);
}
