#include "shell.h"
/**
 * split_line - Split a string into a series of tokens using a delimiter
 * @line: string to split
 * @delimiter: Delimiter
 *Return: Array of tokens terminate in NULL
 */
char **split_line(char *line, char *delimiter)
{
	size_t buffer_size = 64;
	char **alltokens, *token;
	int i;

	alltokens = malloc(sizeof(char *) * buffer_size);
	if (alltokens == NULL)
	{
		perror("Error");
		return (NULL);
	}
	token = strtok(line, delimiter);
	for (i = 0; token; i++)
	{
		alltokens[i] = token;
		token = strtok(NULL, delimiter);
	}
	alltokens[i] = NULL;
	return (alltokens);
}
/**
 * errores - Print a error message
 * @args: Array of token terminate in NULL of getline function
 * @av: Array of pointers terminate in NULL (argv) from main
 * @count: counter of lines of the shell prompt
 * @error: error index
 *Return: void
 */
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
/**
  * _putchar - writes the character c to stdout
  * @c: The character to print
  *
  * Return: On success 1.
  * On error, -1 is returned, and errno is set appropriately.
  */
int _putchar(char c)
{
	write(1, &c, 1);
	return (0);
}
/**
 * _strcmp - Compares two strings
 * @s1: First string to be compare
 * @s2: Second srting to be compare
 *Return: the difference bettwen those teo letters
 */
int _strcmp(char *s1, char *s2)
{
	int i;
	int result = 0;

	for (i = 0; s1[i] != 0 || s2[i] != 0; i++)
	{
		if (!(s1[i] == s2[i]))
		{
			result = s1[i] - s2[i];
			break;
		}
	}
	return (result);
}
/**
 * ignore_signal - Ignore ctrl c signal
 * @signal: signal
 *Return: void
 */
void ignore_signal(int signal __attribute__((unused)))
{
	write(STDOUT_FILENO, "\nGreatTeam $ ", 14);
}
