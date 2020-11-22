#include "shell.h"

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
