#include "shell.h"
/**
 * find_exe_Path - Checks if the file exist in the PATH variable
 * @filename: name of the executable file
 * @index: for checking the current directory at that index compare with token
 * @fullpath: its the path value of the env variable usually PATH
 * Return: A pointer with the pathname NULL otherwise
 */
char *find_exe_Path(char *filename, int index, char *fullpath)
{
	struct stat st;
	char *token, *newpoin, *newpath;
	int size = 0, Dir = 0;

	newpath = _strdup(fullpath);
	token = strtok(newpath, ":");
	while (token)
	{
		Dir += 1;
		if (Dir == (index - 1))
		{ newpoin = _find_exe_cwd(filename);
			if (newpoin != NULL)
				return (newpoin);
		}
		size = (_strlen(token) + _strlen(filename) + 2);
		newpoin = malloc(sizeof(char) * size);
		if (newpoin == NULL)
		{ free(newpath);
			return (NULL);
		}
		newpoin = _strcpy1(newpoin, token, 1);
		newpoin = _strcat(newpoin, filename);
		if (stat(newpoin, &st) == 0)
		{ free(newpath);
			return (newpoin);
		}
		free(newpoin);
		token = strtok(NULL, ":");
		if (token == NULL)
			break;
	}
	free(newpath);
	if (fullpath[_strlen(fullpath) - 1] == ':')
	{
		newpoin = _find_exe_cwd(filename);
		if (newpoin != NULL)
			return (newpoin);
	}
	return (NULL);
}
