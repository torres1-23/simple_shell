#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
	char * directory;
	struct node *next;
} listdir;
extern char **environ;
char *_strdup(char *str);
char *_getenv(const char *name);
char **call_strtok(char *str, char *delimitx);
void print_path(char *name);
listdir *listenv(const char *variable);
listdir *add_node_end(listdir **head, const char *str);
int _setenv(const char *name, const char *value, int overwrite);
int _getposition(const char *name);
int _unsetenv(const char *name);
char *concat (const char *name, const char *value, int index);
void print_path(char *exname);
char *str_concat(char *s1, char *s2);

#endif
