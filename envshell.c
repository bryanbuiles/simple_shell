#include "shell.h"

void envshell(char **args, char *line)
{
    extern char **environ;
    int i;

    for (i = 0; environ[i] != NULL; i++)
    {
        write(1, environ[i], _strlen(environ[i]));
        write(1, "\n", 1);
    }
    (void)args;
    (void)line;
}
