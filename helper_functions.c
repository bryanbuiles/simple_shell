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
	printf("^^^^%s\n", token);
	for (i = 0; token; i++)
	{
		alltokens[i] = token;
		token = strtok(NULL, delimiter);
	}
	alltokens[i] = NULL;
	printf("alltokens: %s\n", alltokens[0]);
	return (alltokens);
}
/**
 * errorMj - Print a error message
 * @message: Array of pointers terminate in NULL
 * @count: counter
 *Return: 0 in succes
 */
int errorMj(char *message[], int count)
{
	int size1 = 0, size2 = 0;
	char *aux = ": not found\n";
	char *str1, *str2;

	size1 = _strlen(message[0]) + 1;
	str1 = malloc(sizeof(char) * size1);
	if (str1 == NULL)
	{
		exit(0);
	}
	str1 = _strcpy1(str1, message[0], 0);
	size2 = _strlen(message[1]) + _strlen(aux) + 1;
	str2 = malloc(sizeof(char) * size2);
	if (str2 == NULL)
	{
		exit(0);
	}
	str2 = _strcpy1(str2, message[1], 0);
	str2 = strcat(str2, aux);
	write(STDOUT_FILENO, str1, size1);
	write(1, ": ", 3);
	_putchar(count + '0');
	write(1, ": ", 3);
	write(STDOUT_FILENO, str2, size2);
	free(str1);
	free(str2);
	return (0);
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
