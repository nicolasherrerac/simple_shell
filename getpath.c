#include "shell.h"

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

	len = strlen(s);
	path = malloc(sizeof(char *) * (len + 5));
	if (path == NULL)
	{
		free(path);
		_exit(1);
	}
	strcpy(path, s);
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
		arr[i] = strdup(str); /*Error 2*/
		memset(str, 0, BUFSIZE);
		i++;
	}
	free(str);
	free(path);
	return (arr);
}
