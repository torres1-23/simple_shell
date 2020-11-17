#include "header.h"

int main(void)
{
	char **p;

	_setenv("ALE", "Alejandro es muy fastidioso", 0);
	for (p = environ; *p; p++)
		printf("%s\n", *p);
	printf("-----------------------------------------\n");
	_setenv("ALE", "Alejandra es muy fastidiosa", 1);
	for (p = environ; *p; p++)
		printf("%s\n", *p);
	return (0);
}
