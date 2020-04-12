#include "shell.h"

int ver_builtins(char *args)
{
    int i;
    builtins_t all[] = {
        {"exit", shellexit},
        {"env", envshell},
        {NULL, NULL}};

    for (i = 0; all[i].arg != NULL; i++)
    {
        if (strcmp(all[i].arg, args) == 0)
        {
            return (1);
        }
    }
    return (2);
}
#include "shell.h"

int apply_builtins(char **args, char *line)
{
    int i;
    builtins_t all[] = {
        {"exit", shellexit},
        {"env", envshell},
        {NULL, NULL}};

    for (i = 0; all[i].arg != NULL; i++)
    {
        if (strcmp(all[i].arg, args[0]) == 0)
        {
            all[i].f(args, line);
            return (1);
        }
    }
    return (0);
}
