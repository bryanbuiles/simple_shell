#include "shell.h"
/**
 * split_line - Split a string into a series of tokens using a delimiter
 * @line: string to split
 * @delimiter: Delimiter
 *Return: Array of tokens terminate in NULL
 */
char **split_line(char *line, char *delimiter)
{
	size_t buffer_size = 200;
	char **alltokens, *token = NULL;
	int i;

	alltokens = malloc(sizeof(char *) * buffer_size);
	if (alltokens == NULL)
	{
		perror("Error");
		return (NULL);
	}
	token = _strtok(line, delimiter);
	for (i = 0; token; i++)
	{
		alltokens[i] = token;
		token = _strtok(NULL, delimiter);
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
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);
	}
	if (error == 2 || error == 3)
	{
		write(STDERR_FILENO, av[0], _strlen(av[0]));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, str, _strlen(str));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, args[0], _strlen(args[0]));
		write(STDERR_FILENO, ": ", 2);
	}
	if (error == 3)
		write(STDERR_FILENO, "Permission denied\n", 18);
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
	write(STDOUT_FILENO, &c, 1);
	return (0);
}
/**
 * _strcmp - Compares two strings
 * @s1: First string to be compare
 * @s2: Second srting to be compare
 *Return: the difference bettwen those teo letters
 */
int _strcmp(const char *s1, const char *s2)
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
	write(STDOUT_FILENO, "\nGreatTeam $ ", 13);
}
