#ifndef _ENVIRONMENT_H_
#define _ENVIRONMENT_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
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

#endif
