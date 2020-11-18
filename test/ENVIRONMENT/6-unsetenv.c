#include "header.h"

int _unsetenv(const char *name)
{
	int index, i, j = 0, len = 0, len1 = 0;
	char **tmp;

	while (environ[len])
		len++;
	if ((index = _getposition(name)) >= 0)
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
	return(0);
}
