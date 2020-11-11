#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *_strdup(char *str);

char **arrword(char *str)
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
	i = 0;
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

int main(int __attribute__((unused))ac, char *av[])
{
	char **wordarr;
	int i = 0;

	wordarr = arrword(av[1]);
	while (wordarr[i]) 
	{
		printf("%s\n", wordarr[i]);
		free(wordarr[i]);
		i++;
	}
	free(wordarr[i]);
	free(wordarr);
	return (0);
}
