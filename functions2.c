#include "shell.h"

/**
 * message_exit - Print exit message.
 * @code: code to switch the message
 * @copy: String
 * @digi: argument digit
 */
void message_exit(int code, char *copy, int digi, char *str, char *buffer)
{
	int j = 0;

	if (code == 0)
	{
		j = 0;
		while (copy[j++])
			;
		write(STDOUT_FILENO, copy, j);
		write(STDOUT_FILENO, ": ", 3);
		write(STDOUT_FILENO, "Invalid argument\n", 18);
		free(copy);
		free(str);
		free(buffer);
		exit(2);
	}
	else if (code == 1)
	{
		write(STDOUT_FILENO, "exit\n", 6);
		free(copy);
		free(str);
		free(buffer);
		exit(digi);
	}
	else
	{
		write(STDOUT_FILENO, "exit\n", 6);
		free(copy);
		free(str);
		free(buffer);
		exit(0);
	}
}
