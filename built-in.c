#include "shell.h"

/**
 * built_in - Handles built in commands.
 * @str: code of built in command
 * @buffer: buffer
 * @status1: status to return on exit
 * Return: 0 if builtin succesful, 1 if not.
 */

int built_in(char *str, char *buffer, int status1)
{
	int i = 0, j = 0, status = 0;
	char *words[] = {"exit", "env", "setenv", "unsetenv", NULL};
	char *space = " ";

	(void)status;
	while (words[i])
	{
		j = 0;
		while (str[j] == words[i][j])
			j++;
		if (i == 0 && ((j == 5) || ((j == 4) && (str[j] == space[0]))))
		{
			free(buffer);
			exit(status1);
		}
		else if (i == 1 && ((j == 4) || ((j == 3) && (str[j] == space[0]))))
		{
			_cenv();
			return (0);
		}
		else if (i == 2 && ((j == 7) || ((j == 6) && (str[j] == space[0]))))
		{
			status = argset(str);
			return (0);
		}
		else if (i == 3 && ((j == 9) || ((j == 8) && (str[j] == space[0]))))
		{
			status = argunset(str);
			return (0);
		}
		if (i == 4)
			return (1);
		i++;
	}
	return (1);
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
