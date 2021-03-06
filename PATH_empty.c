#include "shell.h"
/**
 * PATH_empty - checks if a file is a path name
 * @filename: filename of the executable
 * Return: A pointer of the filename, NULL if not found
 */
char *PATH_empty(char *filename)
{
	struct stat st;

	if (filename[0] == '.' || filename[0] == '/')
	{
		if (stat(filename, &st) == 0)
		{
			filename = _strdup(filename);
			return (filename);
		}
	}
	return (NULL);
}
