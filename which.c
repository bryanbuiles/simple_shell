#include "shell.h"
/**
 * _which - function that finds a file in the variable PATH
 * @filename: it's the file or path to find
 * Return: A pointer of the path or if it doesn't find a file NULL
 */
char *_which(char *filename)
{
	char *newpoin, *fullpath, *ptrPATH;
	int index;

	ptrPATH = "PATH";
	fullpath = _getenv(ptrPATH);

	if (filename[0] == '/')
	{ newpoin = find_slash(filename);
		if (newpoin != NULL)
			return (newpoin);
		return (NULL);
	}
	if (fullpath == NULL)
	{ newpoin = PATH_empty(filename);
		if (newpoin != NULL)
			return (newpoin);
		return (NULL);
	}
	if (filename[0] == '.')
	{ newpoin = _find_exe_cwd(filename);
		if (newpoin != NULL)
			return (newpoin);
		return (NULL);
	}
	else if (fullpath[0] == ':')
	{ newpoin = _find_exe_cwd(filename);
		if (newpoin != NULL)
			return (newpoin);
	}
	index = cwd_inside_PATH(fullpath);
	newpoin = find_exe_Path(filename, index, fullpath);
	if (newpoin != NULL)
		return (newpoin);
	else if (index == 0 && fullpath[_strlen(fullpath) - 1] == ':')
	{ newpoin = _find_exe_cwd(filename);
		if (newpoin != NULL)
			return (newpoin);
	}
	return (NULL);
}
