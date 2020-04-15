#include "shell.h"
/**
 * _which - function that finds a file in the variable PATH
 * @filename: it's the file or path to find
 * Return: A pointer of the path or if it doesn't find a file NULL
 */
char *_which(char *filename)
{
	struct stat st;
	char *newpoin, *newpath, *token, *fullpath;

	fullpath = _getenv("PATH");
	if (filename == NULL)
		return (NULL);
	if (_strcmp(fullpath, "") == 0)
	{
		if (stat(filename, &st) == 0)
		{
			filename = _strdup(filename);
			return (filename);
		}
		else
			return (NULL);
	}
	newpath = _strdup(fullpath);
	token = strtok(newpath, ":");
	while (token)
	{
		token = strtok(NULL, ":");
		if (token == NULL)
			break;
		if (filename[0] == '/' && filename[1] != '/')
		{
			newpoin = malloc(sizeof(char *) * (_strlen(filename) + 1));
			if (newpoin == NULL)
			{
				free(newpath);
				return (NULL);
			}
			newpoin = _strcpy1(newpoin, filename, 0);
		}
		else
		{
			newpoin = malloc(sizeof(char *) * (_strlen(token) + _strlen(filename) + 2));
			if (newpoin == NULL)
			{
				free(newpath);
				return (NULL);
			}
			newpoin = _strcpy1(newpoin, token, 1), newpoin = _strcat(newpoin, filename);
		}
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
