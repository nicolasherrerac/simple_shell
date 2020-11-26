#include "shell.h"

/**
 * print_err - prints error messages to standard error
 * @vars: pointer to struct of variables
 * @msg: message to print
 * Return: void
 */
void print_err(vars_t *vars, char *msg)
{
	char *count;

	_puts(vars->argv[0]);
	_puts(": ");
	count = _uitoa(vars->count);
	_puts(count);
	free(count);
	_puts(": ");
	_puts(vars->av[0]);
	if (msg)
	{
		_puts(msg);
	}
	else
		perror("");
}
