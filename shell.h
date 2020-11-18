#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>

char **call_strtok(char *str, char *delimit);
char *_strdup(char *str);
void execute(char **args);
char *find_path(char *exname);
char *str_concat(char *s1, char *s2);
char *_getenv(const char *name);

#endif /* _HOLBERTON_H_ */
