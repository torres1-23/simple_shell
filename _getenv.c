#include "shell.h"

/**
 * _getenv - function that emulate getenv.
 * @name: name of the enviorment variable.
 * Return: pointer to the value of the variable.
 */

char *_getenv(const char *name)
{
	int index, i = 0;
	char *tmp, **tmp2, *ret = NULL;

	if (name)
	{
		index = _getposition(name);
		if (index >= 0)
		{
			tmp = _strdup(environ[index]);
			tmp2 = call_strtok(tmp, "=");
			ret = _strdup(tmp2[1]);
		}
		else
			return (NULL);
		while (tmp2[i])
		{
			free(tmp2[i]);
			i++;
		}
		free(tmp2);
		free(tmp);
	}
	return (ret);
}

/**
 * _getposition - gets position of desired variable.
 * @name: name of the environment variable.
 * Return: position of desired variable.
 */

int _getposition(const char *name)
{
	int i = 0, j = 0, len = 0, len1 = 0;

	while (environ && environ[i])
	{
		while (environ[i][len] != '=')
			len++;
		len1 = len;
		while (len > 0)
		{
			if (environ[i][j] == name[j])
				j++;
			else
				break;
			len--;
		}
		if (len1 == j && j != 0)
			return (i);
		i++;
		j = 0;
		len = 0;
		len1 = 0;
	}
	return (-1);
}
