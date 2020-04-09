#include "shell.h"

int _strlen(const char *str)
{
    int len;

    for (len = 0; str[len] != 0; len++)
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

    for (i = 0; src[i] != 0; i++)
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
    char **alltokens = malloc(sizeof(char *) * buffer_size);
    char *token;
    int i;

    if (alltokens == NULL)
    {
        perror("Error");
        return (0);
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
