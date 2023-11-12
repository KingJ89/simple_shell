#include "shell.h"

/**
 * free_list - free memory allocated for a list given
 * @list: pointer to a pointer array
 */
void free_list(char **list)
{
	int i;

	if (!list)
		return;

	for (i = 0; list[i]; i++)
	{
		free(list[i]);
		list[i] = NULL;
	}

	free(list), list = NULL;
}
