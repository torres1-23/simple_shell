#include "header.h"

int main ()
{
        char *v = "PATH";

	printf("getenv of PATH: %s\n", _getenv(v));
	print_path(v);

        return(0);
}
