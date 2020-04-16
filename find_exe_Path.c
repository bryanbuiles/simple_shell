#include "shell.h"
/**
 * find_exe_Path - Checks if the file exist in the PATH variable
 * @filename: name of the executable file
 * Return: A pointer with the pathname NULL otherwise
 */
char *find_exe_Path(char *filename)
{
	struct stat st;
	char *newpath, *token, *newpoin;
	int size = 0;

	newpath = getenv("PATH");
	newpath = strdup(newpath);

	token = strtok(newpath, ":");

	while (token)
	{
		token = strtok(NULL, ":");
		if (token == NULL)
			break;
		size = (strlen(token) + strlen(filename) + 2);

		newpoin = malloc(sizeof(char) * size);
		if (newpoin == NULL)
		{
			free(newpath);
			return (NULL);
		}
		newpoin = _strcpy1(newpoin, token, 1);
		newpoin = strcat(newpoin, filename);

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
