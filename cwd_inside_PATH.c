#include "shell.h"
/**
 * cwd_inside_PATH - Checks if the file exist in the PATH variable
 * @fullpathname: value of the variable usually the value of PATH
 * Return: the index of the coincidence of a double colon as current dir
 */
int cwd_inside_PATH(char *fullpathname)
{
	int i, index = 0, k = 0;

	for (i = 1; fullpathname[i]; i++)
	{
		if (fullpathname[i] == ':')
		{
			k += 1;
			if (fullpathname[i + 1] == ':')
			{
				index = k;
				index += 1;
				break;
			}
		}
	}
	return (index);
}
