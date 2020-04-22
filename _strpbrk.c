#include "shell.h"
/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: Address of the string to search the first occurrence
 * @accept: Address of the string to compare with
 * Return: Address of the string modified
 */
char *_strpbrk(char *s, const char *accept)
{
	int i;
	int j;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				s = (s + i);
				return (s);
			}
		}
	}
	s = '\0';
	return (s);

}
