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

int built_in(char *str, char *buffer)
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
			_cexit(str, buffer);
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
		if (i == 4)
			return (1);
		i++;	
	}
	return(0);
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
		exit(EXIT_FAILURE);
	}
	printf("function %s, name %s, value %s\n", argset[0], name, value);
	_setenv(name, value, 1);
}
