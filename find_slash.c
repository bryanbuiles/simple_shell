#include "shell.h"
/**
 * find_slash - Checks if the file exist with the path given
 * @filename: name of the executable file
 * Return: A pointer with the pathname NULL otherwise
 */

char *find_slash(char *filename)
{
	struct stat st;
	char *newpoin;

	newpoin = _strdup(filename);
	if (stat(newpoin, &st) == 0)
		return (newpoin);

	free(newpoin);
	return (NULL);
}
