#include "shell.h"

/**
 * _memset – auto fill with bytes
 * @s: points to memory addresss
 * @b: fills the bye
 * @n: number of bytes to be filled
 * Return: address memory returned
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int initial;

	for (initial = 0; initial < n; initial++)
		s[initial] = b;
	return (s);
}


/**
 * _realloc – directs the block
 * @ptr: points to past block
 * @old_size: size of previous block
 * @new_size: length of block
 *
 * Return: point will be returned
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *point;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	point = malloc(new_size);
	if (!point)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (point);
}

/**
 * ffree – sets free the strings
 * @pp: couple of strings
 */
void ffree(char **pp)
{
	char **any_one = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(any_one);
}
