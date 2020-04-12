#include "shell.h"
/**
 * _which - function that finds a file in the variable PATH
 * @filename: it's the file or path to find
 * Return: A pointer of the path or if it doesn't find a file NULL
 */
/* this function return a pointer with malloc, needs to be free where was call */
char *_which(char *filename)
{
    struct stat st;
    int size = 0;
    char *newpointer, *newpath, *token, *fullpath;

    if (filename == NULL)
        return (NULL);

    /* fullpath ist the value of var PATH */
    fullpath = _getenv("PATH");

  /*newpath will be the copy of PATH value */
    newpath = _strdup(fullpath);

    /*token will be each directory of path */
    token = strtok(newpath, ":");
    
    while (token)
    {
        token = strtok(NULL, ":");
        if (token == NULL)
            break;

        if (filename[0] == '/')
        {
            size = _strlen(filename) + 1;
            newpointer = malloc(sizeof(char *) * (size));
            if (newpointer == NULL)
            {
                free(newpath);
                return (NULL);
            }
            newpointer = _strcpy1(newpointer, filename, 0);
        }
        else
        {
        //else if filename doesn't start with slash (/) 
        /*plus 2 is the null byte and the slash (/)*/
            size = _strlen(token) + _strlen(filename) + 2;
            newpointer = malloc(sizeof(char *) * size);
            if (newpointer == NULL)
            {
                free(newpath);
                return (NULL);
            }
            /* Newpointer will have [token/\0] */
            newpointer = _strcpy1(newpointer, token, 1);
            /* will concatenate the newpointer with filename [token/filename\0] */
            newpointer = _strcat(newpointer, filename);
        } //printf("newpointer = %s\n", newpointer);

        if (stat(newpointer, &st) == 0)
        {
            free(newpath);
         /* newpointer will contain a string ej: /bin/ls 
            and needs to free(newpointer) sometime in the function who call it */
            return (newpointer);
        }
        else
            free(newpointer);
    }
    free(newpath);
    return (NULL);
}
// int main (void)
// {
//     char *ptr;

//     //ptr = _which("ls");
//     ptr = _which("a");
//     //ptr = _which("/bin/ls");
//     if (ptr == NULL)
//         return (1); 
//     printf("%s\n", ptr);

//     free(ptr);
//     return (0);
// }
