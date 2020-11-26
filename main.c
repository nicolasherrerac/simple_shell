#include "shell.h"
/**
 * _sig - handles ^C signal interupt
 * @prompt: unused variable (required for signal function prototype)
 *
 * Return: void
 */
static void _sig(int prompt)
{
	(void) prompt;
	if (flag == 0)
		_puts("\n$ ");
	else
		_puts("\n");
}

/**
 * main - main function for the shell
 * @argc: number of arguments passed to main
 * @argv: array of arguments passed to main
 * @environment: array of environment variables
 *
 * Return: 0 or exit status, or ?
 */
int main(int argc __attribute__((unused)), char **argv, char **environment)
{
	size_t len_buf = 0;
	unsigned int is_pipe = 0, i;
	vars_t vars = {NULL, NULL, NULL, 0, NULL, 0, NULL};

	vars.argv = argv;
	vars.env = make_env(environment);
	signal(SIGINT, _sig);
	if (!isatty(STDIN_FILENO))
		is_pipe = 1;
	if (is_pipe == 0)
		_puts("$ ");
	flag = 0;
	while (getline(&(vars.buffer), &len_buf, stdin) != -1)
	{
		flag = 1;
		vars.count++;
		vars.commands = token_line(vars.buffer, ";");
		for (i = 0; vars.commands && vars.commands[i] != NULL; i++)
		{
			vars.av = token_line(vars.commands[i], "\n \t\r");
			if (vars.av && vars.av[0])
				if (builtins_check(&vars) == NULL)
					path_check(&vars);
		free(vars.av);
		}
		free(vars.buffer);
		free(vars.commands);
		flag = 0;
		if (is_pipe == 0)
			_puts("$ ");
		vars.buffer = NULL;
	}
	if (is_pipe == 0)
		_puts("\n");
	free_env(vars.env);
	free(vars.buffer);
	exit(vars.status);
}
