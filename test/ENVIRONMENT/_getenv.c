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
int main ()
{
	char *v = "NAME";

	printf("Variable name : %s\n", v);
        printf ("using our own _getenv : %s\n", _getenv(v));
        printf("Using the real getenv : %s\n", getenv(v));
        return(0);
}
