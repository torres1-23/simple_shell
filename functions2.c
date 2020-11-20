#include "shell.h"

/**
 * message_exit - Print exit message.
 * @code: code to switch the message
 * @copy: String
 * @digi: argument digit
 * @str: string
 * @buffer: buffer
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
/**
 * built_in - Handles built in commands.
 * @str: code of built in command
 * @buffer: buffer
 */
void built_in(char *str, char *buffer)
{
	int i = 0, j = 0;
	char *words[] = {"exit", "env"};
	char *space = " ";

	while (words[i])
	{
		j = 0;
		while (str[j] == words[i][j])
			j++;
		if (i == 0 && ((j == 5) || ((j == 4) && (str[j] == space[0]))))
			_cexit(str, buffer);
		else if (i == 1 && ((j == 4) || ((j == 3) && (str[j] == space[0]))))
		{
			_cenv();
			break;
		}
		if (i == 2)
			break;
		i++;
	}
}
/**
 * _cenv - prints every variable in the current environment.
 */
void _cenv(void)
{
	int i = 0, j = 0;

	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
			j++;
		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 2);
		i++;
	}
}
