#include "shell.h"
/**
 * _setenv - Initialize a new environment variable, or modify an existing one
 * @name: Variable name
 * @value: Variable value
 * @overwrite: 0 or 1.
 */ 
int _setenv(char *name, char *value, int overwrite)
{
	int index = 0, i = 0, j = 0, len2 = 0;
	char **tmp = NULL;

	if (_getposition(name) >= 0 && overwrite == 0)
		return (0);
	else if ((index = _getposition(name)) >= 0 && overwrite != 0)
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
	return(0);
}
char *concat (char *name, char *value, int index)
{
	int len = 0, len1 = 0, i = 0, j = 0;

	while (name[len])
		len++;
	while (value[len1])
		len1++;

	environ[index] = malloc(sizeof(char) * (len + len1 + 2));
	for (i = 0; i < len; i++)
		environ[index][i] =  name[i];
	environ[index][i++] = '=';
	for (j = 0; j < len1; j++)
		environ[index][i++] = value[j];
	environ[index][i] = '\0';

	return(environ[index]);
}
