#include "header.h"

int _setenv(const char *name, const char *value, int overwrite)
{
	int index, i, j = 0, k, len = 0, len1 = 0, len2 = 0;
	char ** tmp;

	while (name[len])
		len++;
	while (value[len1])
		len1++;
	if (_getposition(name) >= 0 && overwrite == 0)
		return (0);
	else if ((index = _getposition(name)) >= 0 && overwrite != 0)
	{
		for (i = 0; environ[index][i] != '\0'; i++)
			environ[index][i] = '\0';
		environ[index] = malloc(sizeof(char) * (len + len1 + 1));
		for (i = 0; i < len; i++)
			environ[index][i] =  name[i];
		environ[index][i++] = '=';
		for (j = 0; j < len1; j++)
			environ[index][i++] = value[j];
		environ[index][i] = '\0';
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
		environ[i] = malloc(sizeof(char) * (len + len1 + 1));
                for (j = 0; j < len; j++)
                        environ[i][j] = name[j];
                environ[i][j++] = '=';
                for (k = 0; k < len1; k++)
                        environ[i][j++] = value[k];
                environ[i][j] = '\0';
	}
	return(0);
}
