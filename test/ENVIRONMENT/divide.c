#include "header.h"

char **call_strtok(char *str, char *delimit)
{
	char **arrword;
	char *word, *tmp;
	int con = 0, i = 0;

	tmp = _strdup(str);
	word = strtok(str, delimit);
	while (word)
	{
		con++;
		word = strtok(NULL, delimit);
	}
	arrword = malloc(sizeof(char *) * (con + 1));
	word = strtok(tmp, delimit);
	while (word)
	{
		arrword[i] = _strdup(word);
		word = strtok(NULL, delimit);
		i++;
	}
	arrword[i] = NULL;
	free(tmp);
	return (arrword);
}
