#include "shell.h"

/**
 * make_env - make the shell environment from
 * the environment passed to main
 * @env: environment passed to main
 * Return: pointer to the new environment
 */
char **make_env(char **env)
{
	char **ne_env = NULL;
	size_t i;

	for (i = 0; env[i] != NULL; i++)
		;
	ne_env = malloc(sizeof(char *) * (i + 1));
	if (ne_env == NULL)
	{
		perror("Fatal Error");
		exit(1);
	}
	for (i = 0; env[i] != NULL; i++)
		ne_env[i] = _strdup(env[i]);
	ne_env[i] = NULL;
	return (ne_env);
}

/**
 * free_env - free the shell's environment
 * @env: shell's environment
 * Return: void
 */
void free_env(char **env)
{
	unsigned int i;

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);
}
