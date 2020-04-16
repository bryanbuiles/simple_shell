#include "shell.h"

char *find_slash(char *filename)
{
        struct stat st;
        char *newpoin;

        newpoin = malloc(sizeof(char) * (_strlen(filename) + 1));
        if (newpoin == NULL)
                return (NULL);

        newpoin = _strcpy1(newpoin, filename, 0);
        if (stat(newpoin, &st) == 0)
                return (newpoin);

        free(newpoin);
        return (NULL);
}
