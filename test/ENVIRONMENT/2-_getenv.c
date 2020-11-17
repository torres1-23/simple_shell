#include "header.h"

char *_getenv(const char *name)
{
	int index, i = 0;
	char *tmp, **tmp2, *ret = NULL;

	if (name)
	{
		if ((index = _getposition(name)) >= 0)
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
