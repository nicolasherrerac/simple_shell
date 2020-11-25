#include "shell.h"
/**
 * main - first part of the shell.
 * Return: always return 0.
 */
int main(void)
{
	char *args, **arr, *env, **path;
	size_t len = 0;

	signal(SIGINT, _sig);

	args = NULL;
	if (isatty(STDIN_FILENO))
		fun_prompt("$ ");
	while (getline(&args, &len, stdin) != -1)
	{
		if (args[0] != '\n')
		{
			arr = token_line(args);
			if (builtin_func(arr) == 1)
			{
				if (arr[0][0] == '/')
				{
					execute_slash(arr);
					fun_prompt("$ ");
				}
				else
				{
					env = _getenv("PATH");
					path = _getpath(env, arr);
					execute(arr, path);
					if (isatty(STDIN_FILENO))
						fun_prompt("$ ");
				}
			}
			else
				if (isatty(STDIN_FILENO))
					fun_prompt("$ ");
		}
		else
			if (isatty(STDIN_FILENO))
				fun_prompt("$ ");
	}
	free(arr);
	return (0);
}
