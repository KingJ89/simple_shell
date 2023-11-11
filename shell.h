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
#define STAT_EACCES 126

extern char **environ;

char *read_command(void);
char **find_command(char *);
char *find_path(char *);

/*   free memory       */
void free_list(char **);

/*   strings functions */
char *_strdup(char *);
char *_strcpy(char *, char *);
char *_strcat(char *, char *);

/*--------------More strings-----------*/

char *starts_with(const char *haystack, const char *needle);

/*---------------builtins----------------*/
int print_env(char **command);
int exit_shell(char **command, int status);

/*---------prints------------------*/
int _putchar(char);
void _puts(char *);
void print_error(char *, int, char *);
void print_number(int);

/*-----------tools functions--------*/
int positif_digits(char *s);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
#endif
