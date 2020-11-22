#include "shell.h"

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
			perror("Command does not exist");
			printf("\n");
			free(arr);
			_exit(1);
		}
	}
	else
		wait(&status);
}
