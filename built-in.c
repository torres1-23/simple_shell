#include "shell.h"

/**
 * built_in - Handles built in commands.
 * @str: code of built in command
 * @buffer: buffer
 * @exe: name of executable.
 * @cont: number of commands written.
 * @status1: status to return on exit
 * @copy: string without spaces.
 * Return: 0 if builtin succesful, 1 if not.
 */

int built_in(char *exe, int cont, char *str,
char *buffer, int status1, char *copy)
{
	int i = 0, j = 0, nexit = 0;
	char *words[] = {"exit", "env", "setenv", "unsetenv", NULL};
	char *space = " ";

	while (words[i])
	{
		j = 0;
		while (str[j] == words[i][j])
			j++;
		if (i == 0 && ((j == 5) || ((j == 4) && (str[j] == space[0]))))
		{
			nexit = _cexit(exe, cont, str, buffer, status1, copy);
			return (nexit);
		}
		else if (i == 1 && ((j == 4) || ((j == 3) && (str[j] == space[0]))))
		{
			_cenv();
			return (0);
		}
		else if (i == 2 && ((j == 7) || ((j == 6) && (str[j] == space[0]))))
		{
			argset(str);
			return (0);
		}
		else if (i == 3 && ((j == 9) || ((j == 8) && (str[j] == space[0]))))
		{
			argunset(str);
			return (0);
		}
		if (i == 4)
			return (1);
		i++;
	}
	return (1);
}

/**
 * _cexit - Function that cause normal process termination
 * @str: exit command with or without arguments
 * @buffer: buffer
 * @exe: name of executable.
 * @cont: number of commands written.
 * @status1: status to return on exit.
 * @copy: string without spaces.
 * Return: integer of message status.
 */

int _cexit(char *exe, int cont, char *str,
char *buffer, int status1, char *copy)
{
	int i = 0, j = 0, k = 0, digi = 0, fg = 0, message;
	char dig[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'};
	char num[1020] = {'\0'}, *space = " ", *strc = NULL;

	strc = delspace(str, copy, 5);
	if (strc && strc[i])
	{
		for (i = 0; strc[i]; i++)
		{
			j = 0;
			while (dig[j])
			{
				if (strc[i] == dig[j])
				{
					num[k++] = strc[i];
					break;
				}
				if (strc[i] == space[0])
				{
					fg = 1;
					break;
				} j++;
			}
			if (j == 10)
			{
				message = message_exit(0, digi, strc, buffer, exe, cont, 0);
				return (message);
			}
			if (fg == 1)
				break;
		}
		digi = _atoi(num);
		if (digi > 0 && digi <= 255)
			message = message_exit(1, digi, strc, buffer, exe, cont, 0);
		else
			message = message_exit(3, digi, strc, buffer, exe, cont, 0);
	}
	else
		message = message_exit(4, digi, strc, buffer, exe, cont, status1);
	return (message);
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
