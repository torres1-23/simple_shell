#include "shell.h"

/**
 * message_exit - Print exit message.
 * @code: code to switch the message
 * @copy: String
 * @digi: argument digit
 * @str: string
 * @buffer: buffer
 * @exe: name of executable.
 * @cont: number of commands written.
 */

void message_exit(int code, char *copy, int digi, char *str,
char *buffer, char *exe, int cont)
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
		free(copy);
		return;
	}
	else if (code == 1)
	{
		free(copy), free(str), free(buffer);
		exit(digi);
	}
	else if (code == 2)
	{
		write(STDERR_FILENO, exe, i - 1), write(STDERR_FILENO, ": ", 2);
		p_int(cont);
		write(STDERR_FILENO, ": ", 2), write(STDERR_FILENO, copy, j - 1);
		write(STDERR_FILENO, ": not found\n", 12);
		return;
	}
	else
	{
		free(copy), free(str), free(buffer);
		exit(digi - 256);
	}
}

/**
 * built_in - Handles built in commands.
 * @str: code of built in command
 * @buffer: buffer
 * @exe: name of executable.
 * @cont: number of commands written.
 * Return: 0 if builtin succesful, 1 if not.
 */

int built_in(char *exe, int cont, char *str, char *buffer)
{
	int i = 0, j = 0;
	char *words[] = {"exit", "env", "setenv", "unsetenv", NULL};
	char *space = " ";

	while (words[i])
	{
		j = 0;
		while (str[j] == words[i][j])
			j++;
		if (i == 0 && ((j == 5) || ((j == 4) && (str[j] == space[0]))))
		{
			_cexit(exe, cont, str, buffer);
			return (0);
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

/**
 * free_stuff - Frees memory dinamically alocated with malloc in error.
 * @args: pointer to pointers to free.
 * @c: string of chars to free.
 * @b: string of chars to free.
 */

void free_stuff(char **args, char *c, char *b)
{
	int i = 0;

	while (args[i])
		free(args[i++]);
	free(args);
	free(c);
	free(b);
}

/**
 * argset - Set arguments for setenv function.
 * @str: pointer to command string.
 */

void argset(char *str)
{
	char **argset;
	char *name = NULL, *value = NULL;
	int i = 0;

	argset = call_strtok(str, " ");
	while (argset[i])
		i++;
	if (i == 1)
	{
		_cenv();
		i = 0;
		while (argset[i])
			free(argset[i++]);
		free(argset);
		return;
	}
	else if (i == 2)
		name = argset[1];
	else if (i == 3)
	{
		name = argset[1];
		value = argset[2];
	}
	else
	{
		write(STDOUT_FILENO, "Too many arguments\n", 20);
		return;
	}
	_setenv(name, value, 1);
	i = 0;
	while (argset[i])
		free(argset[i++]);
	free(argset);
}
