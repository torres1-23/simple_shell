#include <stdio.h>

int main (int ac, char **av, char **env)
{
	extern char **environ;
	int i = 0;

	(void) ac;
	(void) av;

	while (environ[i] != NULL && env[i] != NULL)
	{
		printf("environ[%d] = %p", i, environ[i]);
		printf(" vs env[%d] = %p\n", i, env[i]);
		i++;
	}
	return (0);
}
