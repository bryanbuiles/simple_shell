#include "shell.h"


//calculates the length of the string pointed to
//by str, excluding the terminating null byte ('\0').
int _strlen(const char *str)
{
    int len;

    for (len = 0; str[len]; len++)
    {
    }
    return (len);
}
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
    return (dest);
}

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
    dest[i] = '\0';
    return (dest);
}
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
	return (haystack  = '\0');
}
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
