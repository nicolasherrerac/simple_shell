#include "shell.h"
/**
 * fun_prompt - Function that print the prompt of the shell.
 * @prompt: receive the parameter to be printed.
 * Return: always return 0.
 */
void fun_prompt(char *prompt)
{
	if (prompt == NULL)
		return;
	write(STDOUT_FILENO, "#cisfun$ ", 9);
}
