#include <stdio.h>

int main (void)
{
	extern char **environ;
	char **p;

	for (p = environ; *p; p++)
		printf("%s\n", *p);
	return (0);
}
