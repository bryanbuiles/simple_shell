#include "shell.h"
 /**
 * shell_prompt - display the shell prompt, and use the issaty
 * function for interactive and none  interactive mode
 * @count: The counter for every shell prompt display
 * Return: A struct with the buffer and the counter
 */
str_p shell_prompt(int count)
{
	str_p buf_count;
	size_t bufersize = 0;
	int bytes, len = 0;
	char *buffer = NULL;

	signal(SIGINT, ignore_signal);
	if (isatty(STDIN_FILENO))
	{
		count++;
		write(1, "GreatTeam $ ", 13);
	}
	else
		count++;

	bytes = getline(&buffer, &bufersize, stdin);
	if (bytes == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		free(buffer);
		exit(0);
	}
	len = _strlen(buffer);
	if (buffer[len - 1] == '\n')
		buffer[len - 1] = '\0';
	buf_count.buffer = buffer;
	buf_count.count = count;

	return (buf_count);

}
