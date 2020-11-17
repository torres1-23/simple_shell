#include "header.h"

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0, j = 0;
	char *tmp, **tmp2;

	while(environ[i] != NULL)
	{
	        if (environ[i][j] == name[j])
		{
			tmp = _strdup(environ[i]);
			tmp2 = call_strtok(tmp, "=");
			j++;
			break;
		}
		i++;
	}
	free(tmp);
	return(tmp2[1]);
}
