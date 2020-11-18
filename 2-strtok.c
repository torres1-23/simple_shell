#include "shell.h"

char **call_strtok(char *str)
{
	char **arrword;
	char *word, *tmp;
	int con = 0, i = 0;

	tmp = _strdup(str);
	word = strtok(str, " ");
	while (word)
	{
		con++;
		word = strtok(NULL, " ");
	}
	arrword = malloc(sizeof(char *) * (con + 1));
	word = strtok(tmp, " ");
	while (word)
	{
		arrword[i] = _strdup(word);
		word = strtok(NULL, " ");
		i++;
	}
	arrword[i] = NULL;
	free(tmp);
	return (arrword);
}
