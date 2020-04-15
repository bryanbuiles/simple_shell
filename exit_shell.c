#include "shell.h"

/**
 * exit_shell - This will run the builtin exit
 * @line: Line buffer of user input
 * @args: Arguments from user
 * @env: Environment
 * Return: Void
 */
void shellexit(char **args, char *line)
{
    free(args);
    free(line);
    exit(0);
}
