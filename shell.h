#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>

#define BUFSIZE 1024
#define DELIM " \t\r\n"

extern char **environ;

/**
 * struct test - structure of variables.
 * @name: input parameter.
 * @func: builtin function.
 */
typedef struct test
{
	char *name;
	int (*func)(char **);
} test_t;

/*PROMPT*/
void fun_prompt(char *prompt);

/*SIGNAL*/
void _sig(int sig);

/*FUNTIONS*/
char **token_line(char *line);
int builtin_func(char **args);
void execute(char **arr, char **args);
void execute_slash(char **arr);
int printenv(char **args);
char *_getenv(char *name);
char **_getpath(char *s, char **args);

/*FUNTIONS BUILTINS*/
int exit_function(char **args);
int help_function(char **args);
int funtion_cd(char **args);

/*HELPÉRS*/
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_memset(char *s, int b, unsigned int n);
char *_strdup(char *str);
int _atoi(char *s);

#endif /*SIMPLE_SHELL_H*/