#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;
char **call_strtok(char *str, char *delimit);
char *_strdup(char *str);
void execute(char **args, char *c, char *b);
char *find_path(char *exname);
char *str_concat(char *s1, char *s2);
char *_getenv(const char *name);
int _getposition(const char *name);
void _cexit(char *str);
int _atoi(char *s);
char *delspace(char *str, int index);

#endif /* _SHELL_H_ */
