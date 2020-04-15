#include "shell.h"
/**
 * _getenv - return a pointer to the value of a environ variable
 * @name: it's the name of the variable -> NAME=value-variable
 * Return: A pointer to the value in the environment or NULL
 */
char *_getenv(const char *name)
{
	int i;
	char *nameVar, *pathvalue;

	//namePath = strdup(name);

	// if (namePath[0] == ':')
	// {
	// 	namePath[0] = ' ';
	// }
	// printf("%s\n", name);

	for (i = 0; environ[i]; i++)
	{
		/* copy the string in order to use strtok so the original doesn't change*/
		nameVar = _strdup(environ[i]);
		/*strtok set all the delim into nulls, and return a pointer*/
		nameVar = strtok(nameVar, "=");
		if ((strcmp(nameVar, name) == 0))
		{
			//printf("%s\n", name);
			pathvalue = _strstr(environ[i], "=");
			free(nameVar);
			//free(name);
			return (++pathvalue);
		}
		free(nameVar);
	}
	free(nameVar);
	//free(name);
	return ("(null)");
}
