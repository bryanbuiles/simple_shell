#include "shell.h"
/* holaaa */
/**
 * _getenv - return a pointer to the value of a environ variable
 * @name: it's the name of the variable -> NAME=value-variable
 * Return: A pointer to the value in the environment or NULL
 */
char *_getenv(const char *name)
{
	int i;
	char *nameVar, *pathvalue, *nameVar1;


	if ((_strcmp(name, "") == 0 || name == NULL))
		return (NULL);

	for (i = 0; environ[i]; i++)
	{
		/* copy the string in order to use strtok so the original doesn't change*/
		nameVar1 = _strdup(environ[i]);
		/*strtok set all the delim into nulls, and return a pointer*/
		nameVar = _strtok(nameVar1, "=");

		if ((_strcmp(nameVar, name) == 0))
		{
			pathvalue = _strstr(environ[i], "=");
			free(nameVar1);
			return (++pathvalue);
		}
		free(nameVar1);
	}
	return (NULL);
}
