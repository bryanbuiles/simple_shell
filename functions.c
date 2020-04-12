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
    dest[i] = '\0'; 

    return (dest);
}

char *_strcpy1(char *dest, char *src, int flag)
{
    // flag = 1 will add a slash at the end of the string
    // flag 2 will add a colon and a space at the end
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

int errorMj(char *message[], int count)
{
    // message[0] = ./a.out
    // message[1] = lslsls

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


int _putchar(char c)
{
    write(1, &c, 1);
    return (0); 
}

