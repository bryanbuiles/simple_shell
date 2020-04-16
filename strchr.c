#include "shell.h"
/**
 * _strchr - Locates a character in a string
 * @s: Address of the array
 * @c: Character
 * Return: The string modified
 */
char *_strchr(char *s, char c)
{
	int i;
	int j;

	for (i = 0; s[i] != 0; i++)
	{
	}
	for (j = 0; j <= i; j++)
	{
		if (s[j] == c)
		{
			s = &s[j];
			break;
		}
		else if (s[j] == 0)
		{
			s = '\0';
		}
	}
	return (s);
}
