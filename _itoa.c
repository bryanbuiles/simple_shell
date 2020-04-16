#include "shell.h"
/* holaaa */
/**
 * _itoa - converts a number to string
 * @n: number
 *Return: string number
 */

char *_itoa(int n)

{
	char *str;
	int i = 0, num = n;

	while (num > 0)
	{
		num /= 10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (i--)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
