#include "shell_prototype.h"

/**
 * _strcmp – compares the two strings
 * @s1: number 1 string
 * @s2: second string
 *
 * Return: a number will be returned
 */
int _strcmp(char *s1, char *s2)
{
	int success = 1, fail = 0, fail_check = -1;

	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (fail);
	else
		return (*s1 < *s2 ? fail_check : success);
}

/**
 * starts_with – looks for it
 * @haystack: string to find
 * @needle: the split string
 *
 * Return: checks the next haystack
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}


/**
 * _strlen – displays the length of string
 * @s: the string to be checked
 *
 * Return: number of words in the length
 */
int _strlen(char *s)
{
	int initial = 0;

	if (!s)
		return (0);

	while (*s++)
		initial++;
	return (initial);
}


/**
 * _strcat – joins two strings
 * @dest: where the thing is heading to
 * @src: location of buffer
 *
 * Return: points to buffer
 */
char *_strcat(char *dest, char *src)
{
	char *result = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (result);
}
