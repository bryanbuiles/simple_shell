#include "shell.h"
/**
 * main - stat example
 *
 * Return: Always 0.
 */

char *_which(char *filename)
{
    struct stat st;
    char *fullpath;
    int size = 0;
    int size2 = 0;
    char *newpointer;
    char *newpath;

    fullpath = getenv("PATH");
    size2 = _strlen(fullpath); /*plus 2 is the null byte and the slash (/)*/
    newpath = malloc(sizeof(char *) * (size2 + 1));
    if (newpath == NULL)
        return (0);

    newpath = _strcpy1(newpath, fullpath, 0);
    char *token = strtok(newpath, ":");
    while (token)
    {
        token = strtok(NULL, ":");
        if (token == NULL)
            break;
        size = _strlen(token) + _strlen(filename) + 2; /*plus 2 is the null byte and the slash (/)*/
        newpointer = malloc(sizeof(char *) * size);
        if (newpointer == NULL)
            return (0);
        newpointer = _strcpy1(newpointer, token, 1);
        newpointer = _strcat(newpointer, filename);
        if (stat(newpointer, &st) == 0)
            return (newpointer);
        else
        {
            free(newpointer);
            newpointer = NULL;
        }
    }
    free(newpath);
    free(newpointer);
    return (0);
}
