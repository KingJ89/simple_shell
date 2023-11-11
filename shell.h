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
#define	STAT_EACCES 126

extern char **environ;

/*   main functions  */
char *read_command(void);
char **find_command(char *);
int execute_command(char **, char **, int);
char *_getenv(char *);
char *find_path(char *);

/*   free memory       */
void free_list(char **);

/*   string functions  */
char *_strdup(char *);
int _strlen(char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);
int _strcmp(char *, char *);

/*   more string functions  */
char *starts_with(const char *, const char *);

/*   prints            */
int _putchar(char);
void _puts(char *);
void print_number(int);
void print_error(char *, int, char *);

/*   tools functions */
int _abs(int);

/*   builtins  */
int exit_shell(char **, int);

#endif
