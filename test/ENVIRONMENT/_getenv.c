#include <stdio.h>
#include <stdlib.h>

char *_getenv(const char *name)
{
	extern char **environ;
	int i = 0, j = 0;

	while(environ[i] != NULL)
	{
		i++;
	        if (environ[i][j] == name[j])
		{
			printf("Variable name: %s\n", name);
			printf("Using our own _getenv %s\n", environ[i]);
			j++;
			break;
		}
	}
	return(environ[i]);
}
int main ()
{
	char *v = "NAME";

        _getenv(v);
        printf("Using the real getenv : %s\n", getenv(v));
        return(0);
}
