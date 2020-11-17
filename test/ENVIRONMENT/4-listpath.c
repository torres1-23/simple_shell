#include "header.h"

listdir *listenv(const char *variable)
{
	listdir *head;
	char *getenvp, **directory;
	int i = 0;

	head = NULL;
	getenvp = _getenv(variable);
	directory = call_strtok(getenvp, ":");
	for (i = 0; directory[i]; i++)
	{
		add_node_end(&head, directory[i]);
	}
	return (head);
}
