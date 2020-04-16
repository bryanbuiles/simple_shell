#include "shell.h"

char *PATH_empty(char *filename)
{
        struct stat st;

        if (stat(filename, &st) == 0)
        {
                filename = strdup(filename);
                return (filename);
        }
        else
                return (NULL);
}
