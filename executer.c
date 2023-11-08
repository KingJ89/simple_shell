#include "shell.h"

/**
 * execute_command - execute shell command givin
 * @command: full command
 * @av: the arguments vector
 *
 * Return: 0 on success, 127 on failure
 */
int execute_command(char **command, char **av)
{
	pid_t pid = fork();
	int stat_loc;

	if (pid == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(av[0]);
			free_list(command);
			exit(STAT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &stat_loc, 0);
		free_list(command);
	}

	return (WEXITSTATUS(stat_loc));
}
