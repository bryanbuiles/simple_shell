#include "shell.h"
/**
 * PATH_empty - checks if a file is a path name
 * @filename: filename of the executable
 * Return: A pointer of the filename, NULL if not found
 */
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
