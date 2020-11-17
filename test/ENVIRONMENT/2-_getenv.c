#include "header.h"

char *_getenv(const char *name)
{
	int i = 0, j = 0, len = 0, len1 = 0;
	char *tmp, **tmp2, *ret = NULL;

	while (environ)
	{
		while (environ[i][len] != '=')
			len++;
		len = len - 1;
		len1 = len;
		while (len > 0)
		{
			if (environ[i][j] == name[j])
				j++;
			else
				break;
			len--;
		}
		if (len1 == j)
		{
			tmp = _strdup(environ[i]);
			tmp2 = call_strtok(tmp, "=");
			ret = _strdup(tmp2[1]);
			break;
		}
		i++;
		j = 0;
		len = 0;
		len1 = 0;
	}
	i = 0;
	while (tmp2[i])
	{
		free(tmp2[i]);
		i++;
	}
	free(tmp2);
	free(tmp);
	if (ret == NULL)
		return (NULL);
	return (ret);
}
