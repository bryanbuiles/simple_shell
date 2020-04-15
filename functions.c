#include "shell.h"
/**
 * _strlen - calculates the length of the string pointed to
 * @str: First string to be compare
 *Return: the number of characters of the string pointed to
 */
int _strlen(const char *str)
{
	int len;

	for (len = 0; str[len]; len++)
	{
	}
	return (len);
}
/**
 * _strcat - concatenates two strings.
 * @dest: First string to concatenate
 * @src: second string to concatenate
 *Return: The resultant concatenated string
 */
char *_strcat(char *dest, const char *src)
{
	int i = 0, j = 0;

	while (dest[i])
	{
		i++;
	}
	while ((dest[i] = src[j]) != 0)
	{
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}
/**
 * _strcpy1 - copies the string pointed by src to the character array dest.
 * @dest: destination string
 * @src: source string to copy
 * @flag: add special character to the end of string
 *Return: The copied array
 */
char *_strcpy1(char *dest, char *src, int flag)
{
	int i;

	for (i = 0; src[i]; i++)
	{
		dest[i] = src[i];
	}
	if (flag == 1)
	{
		dest[i] = '/';
		i++;
	}
	else if (flag == 2)
	{
		dest[i] = ':';
		dest[++i] = ' ';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strstr - The first occurrence of the substring needle in the str haystack
 * @haystack: The main string to be scanned
 * @needle: Is the small string to be searched with haystack
 *Return: A pointer to the first occurrence in haystack
 */
char *_strstr(char *haystack, char *needle)
{
	int i;
	int j = 0;

	if (needle[j] == 0)
		return (haystack);

	for (i = 0; haystack[i] != 0; i++)
	{
		if (haystack[i] == needle[0])
		{
			for (j = 0; needle[j] != 0; j++)
			{
				if (needle[j] != haystack[j + i])
					break;
			}
			if (needle[j] == 0)
			{
				return (haystack + i);
			}
		}
	}
	return (haystack = '\0');
}
/**
 * _strdup - duplicate a string
 * @str: String to duplicate
 *Return: A pointer to null-terminated byte string.
 */
char *_strdup(char *str)
{
	unsigned int i;
	char *s;
	unsigned int size = 0;

	if (str == 0)
		return (0);
	for (i = 0; str[i] != 0; i++)
	{
		size += 1;
	}
	s = malloc(sizeof(char) * (size + 1));
	if (s == 0)
		return (0);
	for (i = 0; i < size; i++)
	{
		s[i] = str[i];
	}
	s[i] = 0;
	return (s);
}
