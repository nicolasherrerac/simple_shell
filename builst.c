#include "shell.h"

/**
 * builtins_check - checks if the command is a builtin
 * @vars: variables
 * Return: pointer to the function or NULL
 */
void (*builtins_check(vars_t *vars))(vars_t *vars)
{
	unsigned int i;
	builtins_t check[] = {
		{"exit", new_exit},
		{"env", _env},
		{NULL, NULL}
	};

	for (i = 0; check[i].f != NULL; i++)
	{
		if (_strcmp(vars->av[0], check[i].name) == 0)
			break;
	}
	if (check[i].f != NULL)
		check[i].f(vars);
	return (check[i].f);
}

/**
 * new_exit - exit program
 * @vars: variables
 * Return: void
 */
void new_exit(vars_t *vars)
{
	int status;

	if (_strcmp(vars->av[0], "exit") == 0 && vars->av[1] != NULL)
	{
		status = _atoi(vars->av[1]);
		if (status == -1)
		{
			vars->status = 2;
			print_err(vars, ":Illegal number: ");
			_puts(vars->av[1]);
			_puts("\n");
			free(vars->commands);
			vars->commands = NULL;
			return;
		}
		vars->status = status;
	}
	free(vars->buffer);
	free(vars->av);
	free(vars->commands);
	free_env(vars->env);
	exit(vars->status);
}

/**
 * _env - prints the current environment
 * @vars: struct of variables
 * Return: void.
 */
void _env(vars_t *vars)
{
	unsigned int i;

	for (i = 0; vars->env[i]; i++)
	{
		_puts(vars->env[i]);
		_puts("\n");
	}
	vars->status = 0;
}
