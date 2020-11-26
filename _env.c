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
	len = _strlen(name);
	while (*env != NULL)
	{
		if (_strcmp(*env, name, len) == 0)
			return (*env);
		env++;
	}
	return (*env);
}

/**
 * _getpath - get the path.
 * @s: number of bytes in the string.
 * @args: arguments that come in.
 * Return: arr returns the concatenated parameters.
 */
char **_getpath(char *s, char **args)
{
	char **arr, *path, *str = NULL, *del, *token;
	int len;
	int i;

	len = _strlen(s);
	path = malloc(sizeof(char *) * (len + 5));
	if (path == NULL)
	{
		free(path);
		_exit(1);
	}
	_strcpy(path, s);
	token = strtok(path, ":");
	arr = malloc(sizeof(char *) * BUFSIZE + 5);
	if (arr == NULL)
	{
		free(arr);
		_exit(1);
	}
	str = malloc(sizeof(char) * BUFSIZE);
	if (str == NULL)
	{
		free(str);
		_exit(1);
	}
	del = "/";
	i = 0;
	while (token != NULL)
	{
		_strcat(str, token); /*Error 1*/
		_strcat(str, del);
		_strcat(str, args[0]);
		token = strtok(NULL, ":");
		arr[i] = _strdup(str); /*Error 2*/
		_memset(str, 0, BUFSIZE);
		i++;
	}
	free(str);
	free(path);
	return (arr);
}
