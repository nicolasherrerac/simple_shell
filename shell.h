#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>

/**
 * struct variables - variables
 * @av: command line arguments
 * @buffer: buffer of command
 * @env: environment variables
 * @count: count of commands entered
 * @argv: arguments at opening of shell
 * @status: exit status
 * @commands: commands to execute
 */
typedef struct variables
{
	char **av;
	char *buffer;
	char **env;
	size_t count;
	char **argv;
	int status;
	char **commands;
} vars_t;

/**
 * struct builtins - struct for the builtin functions
 * @name: name of builtin command
 * @f: function for corresponding builtin
 */
typedef struct builtins
{
	char *name;
	void (*f)(vars_t *);
} builtins_t;

unsigned int flag;

ssize_t _puts(char *str);
char *_strdup(char *strtodup);
int _strcmp(char *strcmp1, char *strcmp2);
char *_strcat(char *strc1, char *strc2);
unsigned int _strlen(char *str);

char **token_line(char *buffer, char *del);
char **_realloc(char **ptr, size_t *size);

void (*builtins_check(vars_t *vars))(vars_t *vars);
void new_exit(vars_t *vars);
void _env(vars_t *vars);

char **make_env(char **env);
void free_env(char **env);

int _atoi(char *str);

void path_check(vars_t *vars);
int execute_path(char *command, vars_t *vars);
char *match_path(char **env);
int execute_cwd(vars_t *vars);
int check_dir(char *str);

void print_err(vars_t *vars, char *msg);

char *_uitoa(unsigned int count);

#endif /*SIMPLE_SHELL_H*/
