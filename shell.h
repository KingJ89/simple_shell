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
#define	STAT_ILLEGAL_NUMBER 2

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
void print_error(char *, int, char *, char *, char *);

/*   tools functions */
int _abs(int);
int _atoi(char *);
int positif_digits(char *);
char *_itoa(int);

/*   handlers        */
void handle_comments(char *);
void handle_variables(char **, int);

/*   builtins         */
int exit_shell(char **, int, char **, int);
int print_env(char **);
int handle_cd(char **, char **, int);

#endif
