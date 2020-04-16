#include "shell.h"
/**
 * _which - function that finds a file in the variable PATH
 * @filename: it's the file or path to find
 * Return: A pointer of the path or if it doesn't find a file NULL
 */
char *_which(char *filename)
{
	char *newpoin, *fullpath, *ptrPATH;

	ptrPATH = "PATH";
	fullpath = _getenv(ptrPATH);

	if (filename == NULL)
		return (NULL);

	else if (filename[0] == '/')
	{
		newpoin = find_slash(filename);
		if (newpoin == NULL)
			return (NULL);
		else
			return (newpoin);
	}
	if (fullpath == NULL)
	{
		newpoin = PATH_empty(filename);
		if (newpoin == NULL)
			return (NULL);
		else
			return (newpoin);
	}

	else if (fullpath[0] == ':' || filename[0] == '.')
	{
		newpoin = _find_exe_cwd(filename);
		if (newpoin == NULL)
			return (NULL);
		else
			return (newpoin);
	}
	newpoin = find_exe_Path(filename);
	if (newpoin != NULL)
		return (newpoin);
	return (NULL);
}
