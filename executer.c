#include "shell.h"

/**
 * execute_command - execute shell command givin
 * @command: full command
 * @av: the arguments vector
 * @count: index of error
 *
 * Return: 0 on success, 127 on failure
 */
int execute_command(char **command, char **av, int count)
{
	pid_t pid;
	int stat_loc;
	char *path = NULL;

	path = find_path(command[0]);
	if (!path)
	{
		print_error(av[0], count, command[0], "not found", NULL);
		free_list(command);
		return (STAT_FAILURE);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error pid:");
		exit(STAT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(path, command, environ) == -1)
		{
			if (errno == EACCES)
				exit(STAT_EACCES);
			free(path), path = NULL;
			free_list(command);
		}
	}
	else
	{
		waitpid(pid, &stat_loc, 0);
		free(path), path = NULL;
		free_list(command);
	}

	return (WEXITSTATUS(stat_loc));
}
