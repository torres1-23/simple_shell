#include "header.h"

void print_path(char *name)
{
	char *getenvp, **directory;
	int i = 0;

	getenvp = _getenv(name);
	directory = call_strtok(getenvp, ":");
	for (i = 0; directory[i]; i++)
		printf("%s\n", directory[i]);
}
