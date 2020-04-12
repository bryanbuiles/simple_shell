#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _getenv - return a pointer to the value of a environ variable
 * @name: it's the name of the variable -> NAME=value-variable
 * Return: A pointer to the value in the environment or NULL if there is not match
 */
extern char **environ;

char *_getenv(const char *name)
{
        int i;
        char *nameVar, *pathvalue;
        for(i = 0; environ[i]; i++)
        {
         /* copy the string in order to use strtok so the original doesn't change*/
                nameVar = _strdup(environ[i]);
         /*strtok set all the delim into nulls, and return a pointer to the first string */
                nameVar = strtok(nameVar, "=");
                if((strcmp(nameVar, name) == 0))
                {
                        pathvalue = _strstr(environ[i],"=");
                        free(nameVar);
                        return(++pathvalue);
                }
                free(nameVar);
        }
        free(nameVar);
        return ("(null)");
}

// int main (void)
// {
//         printf("%s\n", _getenv("PATH"));
//         return (0);
// }
