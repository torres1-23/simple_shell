#include "header.h"

int main(void)
{
	char **p;
	int i = 0;

	_setenv("ALE", "Alejandro es muy fastidioso", 0);
	for (p = environ; *p; p++)
		printf("%s\n", *p);
	printf("-----------------------------------------\n");
	_setenv("ALE", "Alejandra es muy fastidiosa", 1);
	for (p = environ; *p; p++)
		printf("%s\n", *p);
	printf("-----------------------------------------\n");
	_unsetenv("ALE");
	for (p = environ; *p; p++)
		printf("%s\n", *p);
	while (environ[i])
	{
		free(environ[i]);
		i++;
	}
	free(environ);
	return (0);
}
