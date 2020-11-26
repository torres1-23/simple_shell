#include "shell.h"

/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @name: Variable name
 * @value: Variable value
 * @overwrite: 0 or 1.
 * Return:  in succes.
 */

int _setenv(char *name, char *value, int overwrite)
{
	int index = 0, i = 0, j = 0, len2 = 0;
	char **tmp = NULL;

	index = _getposition(name);
	if (index >= 0 && overwrite != 0)
	{
		for (i = 0; environ[index][i] != '\0'; i++)
			environ[index][i] = '\0';
		concat(name, value, index);
	}
	else
	{
		while (environ[len2])
			len2++;
		tmp = malloc(sizeof(char *) * (len2 + 1));
		for (i = 0; i < len2; i++)
			tmp[i] = _strdup(environ[i]);
		tmp[i] = '\0';
		environ = malloc(sizeof(char *) * (len2 + 2));
		for (i = 0; i < len2; i++)
			environ[i] = _strdup(tmp[i]);
		while (tmp[j])
		{
			free(tmp[j]);
			j++;
		}
		free(tmp);
		concat(name, value, j);
	}
	return (0);
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
		write(STDERR_FILENO, "Too many arguments\n", 20);
		return;
	}
	_setenv(name, value, 1);
	i = 0;
	while (argset[i])
		free(argset[i++]);
	free(argset);
}

/**
 * _unsetenv - Erases an environment variable
 * @name: Variable name
 * Return: 0 if success.
 */

int _unsetenv(const char *name)
{
	int index, i, j = 0, len = 0, len1 = 0;
	char **tmp;

	while (environ[len])
		len++;
	index = _getposition(name);
	if (index >= 0)
	{
		while (environ[index][len1])
			len1++;
		for (i = 0; i < len1; i++)
			environ[index][i] = '\0';
		tmp = malloc(sizeof(char *) * len);
		for (i = 0; i < len; i++)
		{
			if (environ[i][0])
				tmp[j++] = _strdup(environ[i]);
		}
		tmp[j] = '\0';
		for (i = 0; i < len - 1; i++)
			environ[i] = _strdup(tmp[i]);
		environ[i] = '\0';
		j = 0;
		while (tmp[j])
		{
			free(tmp[j]);
			j++;
		}
		free(tmp);
	}
	return (0);
}

/**
 * argunset - Set arguments for unsetenv function.
 * @str: pointer to command string.
 */

void argunset(char *str)
{
	char **argset;
	char *name = NULL;
	int i = 0;

	argset = call_strtok(str, " ");
	while (argset[i])
		i++;
	if (i == 1)
	{
		write(STDERR_FILENO, "Too few arguments\n", 20);
		return;
	}
	else if (i == 2)
		name = argset[1];
	else
	{
		write(STDERR_FILENO, "Too many arguments\n", 20);
		return;
	}
	_unsetenv(name);
	i = 0;
	while (argset[i])
		free(argset[i++]);
	free(argset);
}
