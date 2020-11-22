#include "shell.h"
/**
 * builtin_func - interpreter that has a number of functions.
 * @args: arguments that come in.
 * Return: return 1 if .
 */
int builtin_func(char **args)
{
	test_t builtins[] = {
	    {"exit", exit_function},
	    {"env", printenv},
	    {"help", help_function},
	    {"cd", funtion_cd},
	    {NULL, NULL}};
	int i, j, len;

	i = 0;
	j = 0;
	len = 0;
	while (args[0][len] != '\0')
	{
		len++;
	}
	while (builtins[i].name != NULL)
	{
		j = 0;
		while (j < len)
		{
			if (builtins[i].name[j] != args[0][j])
				break;
			j++;
		}
		if (builtins[i].name[j] == args[0][j])
		{
			builtins[i].func(args);
			return (0);
		}
		i++;
	}
	return (1);
}
