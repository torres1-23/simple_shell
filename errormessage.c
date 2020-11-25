#include "shell.h"

/**
 * message_exit - Print exit message.
 * @code: code to switch the message
 * @digi: argument digit
 * @copy: string without spaces.
 * @buffer: buffer
 * @exe: name of executable.
 * @cont: number of commands written.
 * @status1: status to return on exit
 * Return: int
 */

int message_exit(int code, int digi, char *copy,
char *buffer, char *exe, int cont, int status1)
{
	int j = 0, i = 0;

	while (exe[i++])
		;
	while (copy[j++])
		;
	if (code == 0)
	{
		write(STDERR_FILENO, exe, i - 1), write(STDERR_FILENO, ": ", 2);
		p_int(cont);
		write(STDERR_FILENO, ": exit: Illegal number: ", 24);
		write(STDERR_FILENO, copy, j), write(STDERR_FILENO, "\n", 1);
		return (2);
	}
	else if (code == 1)
	{
		free(buffer);
		exit(digi);
	}
	else if (code == 2)
	{
		write(STDERR_FILENO, exe, i - 1), write(STDERR_FILENO, ": ", 2);
		p_int(cont);
		write(STDERR_FILENO, ": ", 2), write(STDERR_FILENO, copy, j - 1);
		write(STDERR_FILENO, ": not found\n", 12);
		return (127);
	}
	else if (code == 3)
	{
		free(buffer);
		exit(digi - 256);
	}
	else
	{
		free(buffer);
		exit(status1);
	}
}
