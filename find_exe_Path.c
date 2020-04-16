#include "shell.h"

char *find_exe_Path(char *filename)
{
       	struct stat st;
        char *newpath, *token, *newpoin;
        int size = 0;

        newpath = getenv("PATH");
        newpath = strdup(newpath);

        token = strtok(newpath, ":");

        while (token)
        { 
                token = strtok(NULL, ":");
                if (token == NULL)
                        break;
                size = (strlen(token) + strlen(filename) + 2);
                //printf("size = %i, dire = %s, file = %s \n", size, token, filename);
                newpoin = malloc(sizeof(char) * size);//(strlen(token) + strlen(filename) + 2));
                if (newpoin == NULL)
                { 
                        free(newpath);
                        return (NULL);
                }
                newpoin = _strcpy1(newpoin, token, 1);
                newpoin = strcat(newpoin, filename);

                if (stat(newpoin, &st) == 0)
                { 
                        free(newpath);
                        return (newpoin);
                } 
                free(newpoin);
        } 
        free(newpath);
        return (NULL);
}
