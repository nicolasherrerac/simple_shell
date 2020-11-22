#include "shell.h"
/**
 * _getenv - Function that obtain enviroment.
 * @name: input parameter.
 * Return: *env
 */
char *_getenv(char *name)
{
	char **env;
	int len;

	env = environ;
	len = strlen(name);

	while (*env != NULL)
	{
		if (strncmp(*env, name, len) == 0)
			return (*env);
		env++;
	}
	return (*env);
}
