#include "shell.h"
/**
 * _which - function that finds a file in the variable PATH
 * @filename: it's the file or path to find
 * Return: A pointer of the path or if it doesn't find a file NULL
 */
char *_which(char *filename)
{
	struct stat st;
	char cwd[PATH_MAX];
	char *newpoin, *newpath, *token, *fullpath, *ptrPATH, *current;
	int sizecurrent;

	ptrPATH = "";

	//fullpath = ":/home/vagrant/.vscode-server/bin/78a4c91400152c0f27ba4d363eb56d2835f9903a/bin:/home/vagrant/.vscode-server/bin/78a4c91400152c0f27ba4d363eb56d2835f9903a/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games";

	if (filename == NULL)
		return (NULL);

	if (strcmp(ptrPATH, "") == 0)
	{
		if (stat(filename, &st) == 0)
		{
			filename = strdup(filename);
			printf(">>>%s\n", filename);
			return (filename);
		}
		else
		{
			return (NULL);
		}
	}
	// if (ptrPATH[0] == ':')
	// {
	// 	getcwd(cwd, sizeof(cwd));
	// 	sizecurrent = strlen(filename) + strlen(cwd) + 1;
	// 	current = malloc(sizeof(char) * sizecurrent);
	// 	if (current == NULL)
	// 		return (NULL);
	// 	strcpy(current, cwd);
	// 	strcat(current, filename);
	// 	if (stat(current, &st) == 0)
	// 	{
	// 		return (current);
	// 	}

	// }

	fullpath = _getenv(ptrPATH);
	newpath = _strdup(fullpath);
	token = strtok(newpath, ":");

	while (token)
	{
		token = strtok(NULL, ":");
		if (token == NULL)
			break;
		if (filename[0] == '/')
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
			newpoin = _strcpy1(newpoin, token, 1);
			newpoin = _strcat(newpoin, filename);
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
