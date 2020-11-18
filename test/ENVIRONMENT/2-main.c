#include "header.h"

int main (int ac, char *av[])
{
	char *env;

	while(ac > 1)
	{
		printf("Variable name : %s\n", av[1]);
		env = _getenv(av[1]);
		printf ("Using our own _getenv : %s\n", env);
		printf("Using the real getenv : %s\n", getenv(av[1]));
		free(env);
		break;
	}
	return (0);
}
