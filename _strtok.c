#include "shell.h"
/**
 * _strtok - tokenize a string by the delimeters
 * @str: Pointer to the string
 * @delim: string of delimeters
 * Return: a pointer to the string tokeinze, NULL otherwise
 */
char *_strtok(char *str, const char *delim)
{
	static char *ptrAux;
	char *token = NULL;
	size_t len = 0;

	if (delim == NULL)
		return (str);
	if (str == NULL)
	{
		str = ptrAux;
		if (str == NULL)
			return (NULL);
	}
	/* finds if the first characters are delimeters and avoid them to be tokens */
	len = _strspn(str, delim);
	str += len;
	if (*str == '\0')
	{
		return (NULL);
	}
	token = str;
	/* str will be pointing to the first delimeter found */
	str = _strpbrk(token, delim);
	/* if str is not null means there are more strings to be tokenize */
	if (str != NULL)
	{
		/* will make the delimeter  null character */
		*str = '\0';
		/*will be poiting to the next position of the found delimeter */
		/* which will be null*/
		ptrAux = str + 1;
	}
	/* if there are no more tokens will be null */
	else
		ptrAux = NULL;
	return (token);
}
