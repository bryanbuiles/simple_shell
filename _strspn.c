#include "shell.h"
/**
 * _strspn - Gets the length of a prefix substring
 * @s: Addres of the string
 * @accept: string with amount of bytes
 * Return: an integer
 */
unsigned int _strspn(char *s, const char *accept)
{
	int i, j;
	unsigned int k = 0;

	for (i = 0; s[i] != '\0' && s[i] != ' '; i++)
	{
		for (j = 0; accept[j] != '\0'; j++)
		{
			if (s[i] == accept[j])
			{
				k++;
				break;
			}
		}
	}
	return (k);
}
