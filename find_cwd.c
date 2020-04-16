#include "shell.h"

char *_find_exe_cwd(char *filename) 
{
        char *buffer = NULL;
        char *current = NULL;
        int sizecurrent = 0;
        struct stat st;

        buffer = getcwd(NULL, 0);
        if(buffer == NULL)
        {
                perror("getcwd() error");
                return (NULL);
        }
        sizecurrent = _strlen(filename) + _strlen(buffer) + 3;
        printf("size, %i filename = %s buffer = %s\n",sizecurrent, filename, buffer);
        current = malloc(sizeof(char) * sizecurrent);
        if (current == NULL)
                return (0);

        _strcpy1(current, buffer, 1);
        free(buffer);
        _strcat(current, filename);

        if (stat(current, &st) == 0)
        {
                printf("found %s\n", current);
                return (current);
        }
        printf("not found in the cwd %s\n", current);
        free(current);
        return (NULL);
}
