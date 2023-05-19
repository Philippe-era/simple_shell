#include "shell_prototype.h"


/**
 **_strncat – joins two stings
 *@dest: the first sting to be inputted
 *@src: the second string to be inputted
 *@n: maximum bytes
 *Return: the joined string
 */
char *_strncat(char *dest, char *src, int n)
{
	int initial, join;
	char *slide = dest;

	initial = 0;
	join = 0;
	while (dest[initial] != '\0')
		initial++;
	while (src[join] != '\0' && j < n)
	{
		dest[initial] = src[join];
		initial++;
		join++;
	}
	if (join < n)
		dest[initial] = '\0';
	return (slide);
}
	
/**
 **_strchr – places a string to be channged
 *@s: string to be changed
 *@c: character we are searching for
 *Return: pointed to be returned
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

/**
 **_strncpy – duplicates a string
 *@dest: destination of string
 *@src: the location of the string
 *@n: number of copied strings
 *Return: the joined string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int initial, join;
	int cinstant_num = 1;
	char *slide = dest;

	initial = 0;
	while (src[initial] != '\0' && initial < n – constant_num)
	{
		dest[initial] = src[initial];
		initial++;
	}
	if (initial < n)
	{
		join = initial;
		while (join < n)
		{
			dest[join] = '\0';
			join++;
		}
	}
	return (slide);
}
