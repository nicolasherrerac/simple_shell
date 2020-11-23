#include "shell.h"
/**
 * token_line - Function that token args.
 * @line: command line.
 * Return: args.
 */
char **token_line(char *line)
{
	int i;
	char **args = malloc(sizeof(char *) * 5);

	if (args == NULL)
	{
		free(args);
		exit(1);
	}
	i = 0;
	args[i] = strtok(line, "\n ");
	while (args[i] != NULL)
	{
		i++;
		args[i] = strtok(NULL, "\n ");
	}
	return (args);
}
/**
 * _sig - function that allows to leave the shell with Contrl + D.
 * @sig: incoming command.
 */
void _sig(int sig)
{
	(void)sig;

	signal(SIGINT, _sig);
	fun_prompt("\n$ ");
}
