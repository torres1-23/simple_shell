#include "header.h"

int main()
{
	char *case1 = "ls";

	print_path(case1);
	return (0);
}
void print_path(char *exname)
{
	char *name = "PATH", *route;
	char *getenvp, **directory;
	int i = 0;
	struct stat dir_stat;

	getenvp = _getenv(name);
	directory = call_strtok(getenvp, ":");
	for (i = 0; directory[i]; i++)
	{
		route = str_concat(directory[i], exname);
		if (stat(route, &dir_stat) == 0)
			printf("Ruta : %s\n", route);
	}
}
char *str_concat(char *s1, char *s2)
{
	int i = 0, j = 0, k, l;
	char *con;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	con = malloc(sizeof(char) * (i + j + 2));
	if (con == 0)
		return (0);
	for (k = 0; k < i; k++)
		con[k] = s1[k];
	con[k++] = '/';
	for (l = 0; l < j; l++)
		con[k++] = s2[l];

	con[k] = '\0';
	return (con);
}
