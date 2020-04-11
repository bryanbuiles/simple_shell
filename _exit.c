#include "shell.h"

void shellexit(char **args, char *line)
{
    free(args);
    free(line);
    //(void)env;
    exit(0);
}
