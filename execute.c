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
		perror("Error");
		free(arr);
		free(args);
		_exit(1);
	}
	if (pid == 0)
	{
		i = 0;
		while (args[i] != NULL)
		{
			if (execve(args[i], arr, NULL) == -1)
				i++;
		}
		perror("Error");
		free(arr);
		_exit(1);
	}
	else
		wait(&status);
}
