#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

#define DELIM " \t\n"

#define STAT_FAILURE 127

extern char **environ;
char **find_command(char *input);

char *read_command(void);
char **find_command(char *input);
int excute_command(char **command, char **av);

/*   free memory       */
void free_list(char **);

/*   strings functions */
char *_strdup(char *);

#endif
