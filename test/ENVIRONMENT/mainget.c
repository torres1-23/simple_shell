#include "header.h"

int main ()
{
	char *v = "PATH";

	printf("Variable name : %s\n", v);
	printf ("using our own _getenv : %s\n", _getenv(v));
	printf("Using the real getenv : %s\n", getenv(v));
	return(0);
}
