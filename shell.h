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
#include <errno.h>

extern char **environ;
char **call_strtok(char *str, char *delimit);
char *_strdup(char *str);
char *find_path(char *exname);
int execute(char *exe, int cont, char **args, char *b);
char *str_concat(char *s1, char *s2);
char *_getenv(const char *name);
int _getposition(const char *name);
int _atoi(char *s);
char *delspace(char *str, char *copy);
int built_in(char *str, char *buffer, int status1);
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
char *str_concatdot(char *s1, char *s2);
void message_error(int code, char *exe, int cont, char *arg);
void err_hd(int stat, char *path);

#endif /* _SHELL_H_ */
