#include "shell.h"

/**
 * message_error - Print exit message.
 * @code: code to switch the message
 * @exe: name of executable.
 * @cont: number of commands written.
 * @arg: status to return on exit
 * Return: int
 */

void message_error(int code, char *exe, int cont, char *arg)
{
	int i = 0, j = 0;

	while (exe[i++])
		;
	while (arg[j++])
		;
	if (code == 0)
	{
		write(STDERR_FILENO, exe, i - 1), write(STDERR_FILENO, ": ", 2);
		p_int(cont);
		write(STDERR_FILENO, ": ", 2), write(STDERR_FILENO, arg, j - 1);
		write(STDERR_FILENO, ": Permission denied\n", 20);
	}
	else
	{
		write(STDERR_FILENO, exe, i - 1), write(STDERR_FILENO, ": ", 2);
		p_int(cont);
		write(STDERR_FILENO, ": ", 2), write(STDERR_FILENO, arg, j - 1);
		write(STDERR_FILENO, ": not found\n", 12);
	}
}
