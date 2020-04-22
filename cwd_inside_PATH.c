#include "shell.h"
/**
 * cwd_inside_PATH - Checks if the file exist in the PATH variable
 * @fullpathname: value of the variable usually the value of PATH
 * Return: the index of the coincidence of a double colon as current dir
 */
int cwd_inside_PATH(char *fullpath)
{
	int i, index = 0, Directory = 0;

	for (i = 1; fullpath[i]; i++)
	{
		if (fullpath[i] == ':')
		{
			Directory += 1;
			if (fullpath[i + 1] == ':')
			{
				index = Directory + 1;
				break;
			}
		}
	}
	return (index);
}
