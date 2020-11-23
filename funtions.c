#include "shell.h"
/**
 * builtin_func - interpreter that has a number of functions.
 * @args: arguments that come in.
 * Return: return 1 if.
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
/**
 * funtion_cd - function that allows access to directories.
 * @args: arguments that come in.
 * Return: return 1 if fails.
 */
int funtion_cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Error: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Error");
		}
	}
	return (1);
}
/**
 * exit_function - function that allows to leave.
 * @args: arguments that come in.
 * Return: return 1 if fails.
 */
int exit_function(char **args)
{
	int status;

	if (args[1] == NULL)
	{
		free(args);
		_exit(0);
	}
	else
	{
		status = _atoi(args[1]);
		free(args);
		_exit(status);
	}
	return (1);
}
/**
 * printenv - function that prints the environment variable.
 * @args: arguments that come in.
 * Return: return 1 if fails.
 */
int printenv(char **args)
{
	int i, j;
	/*unsigned int *value;*/
	i = 0;
	j = 0;
	if (args[1] == NULL)
	{
		while (environ[i] != NULL)
		{
			j = 0;
			while (environ[i][j] != '\0')
			{
				putchar((environ[i])[j]);
				/*return(value);*/
				j++;
			}
			i++;
			printf("\n");
		}
		return (0);
	}
	putchar('\n');
	return (1);
}
/**
 * help_function - help function
 * @args: arguments that come in.
 * Return: return 1 if fails.
 */
int help_function(char **args)
{
	(void)args;

	fun_prompt("\n\t***SIMPLE SHELL***\t\n\n");
	fun_prompt("Display information about commands.\n");
	fun_prompt("Entry [command name] [arguments]\n");
	fun_prompt("Example:  ls -la\n");
	fun_prompt("\n\n");
	return (1);
}