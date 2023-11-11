#include "shell.h"

/**
 * starts_with - checks if needle starts with haystaach searches.
 * @haystack: string to be searched.
 * @needle: the substring to be found.
 * Return: address of next char or NULL on error.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}
