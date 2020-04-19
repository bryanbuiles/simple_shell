#include "shell.h"
/**
 * _find_exe_cwd - Checks if the file exist in the current directory
 * @filename: name of the executable file
 * Return: A pointer with the pathname NULL otherwise
 */

char *_find_exe_cwd(char *filename)
{
	char *buffer = NULL;
	char *current = NULL;
	int sizecurrent = 0;
	struct stat st;

	
	buffer = getcwd(NULL, 0);
	if (buffer == NULL)
		return (NULL);

	sizecurrent = _strlen(filename) + _strlen(buffer) + 3;
	current = malloc(sizeof(char) * sizecurrent);
	if (current == NULL)
		return (0);

	_strcpy1(current, buffer, 1);
	_strcat(current, filename);
	free(buffer);
	if (stat(current, &st) == 0)
		return (current);
	free(current);
	return (NULL);
}
