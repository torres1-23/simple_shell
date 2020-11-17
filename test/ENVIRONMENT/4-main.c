#include "header.h"

int main(void)
{
	char *var = "PATH";
	listdir *list;
	int i = 0;

	list = listenv(var);
	while (list)
	{
		printf("Directory %d: %s\n", i, list->directory);
		list = list->next;
		i++;
	}
	return (0);
}