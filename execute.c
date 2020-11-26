#include "shell.h"
/**
 * execute - Function that execute the command line.
 * @arr: string.
 * @args: arguments.
 */
void execute(char **arr, char **args)
{
	pid_t pid;
	int i, status;

	status = 0;
	pid = fork();

	if (pid == -1)
	{
		write(STDERR_FILENO, "command not found", 17);
		free(arr);
		free(args);
		_exit(1);
	}
	if (pid == 0)
	{
		i = 0;
		while (args[i] != NULL)
		{
			if (execve(args[i], arr, environ) == -1)
				i++;
		}
		perror("command not found");
		free(arr);
		_exit(1);
	}
	else
		wait(&status);
}
/**
 * execute_slash - función execute_slash.
 * @arr: function that executes the slash.
 */
void execute_slash(char **arr)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		free(arr);
		_exit(1);
	}
	if (pid == 0)
	{
		if (execve(arr[0], arr, environ) == -1)
		{
			perror("Command not found");
			_putchar('\n');
			free(arr);
			_exit(1);
		}
	}
	else
		wait(&status);
}
