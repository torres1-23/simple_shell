#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

extern char **environ;
char **call_strtok(char *str, char *delimit);
char *_strdup(char *str);
char *find_path(char *exname);
int execute(char *exe, int cont, char **args, char *b);
char *str_concat(char *s1, char *s2);
char *_getenv(const char *name);
int _getposition(const char *name);
void _cexit(char *exe, int cont, char *str,
char *buffer, int status1, char *copy);
int _atoi(char *s);
char *delspace(char *str, char *copy, int index);
int message_exit(int code, int digi, char *copy,
char *buffer, char *exe, int cont, int status1);
int built_in(char *exe, int cont, char *str,
char *buffer, int status1, char *copy);
void _cenv(void);
void free_stuff(char **args, char *b);
int _setenv(char *name, char *value, int overwrite);
void argset(char *str);
char *concat(char *name, char *value, int index);
int _unsetenv(const char *name);
void argunset(char *str);
void handle_sigint(int i);
void free_bidimensional(char **array);
void p_int(int n);

#endif /* _SHELL_H_ */
