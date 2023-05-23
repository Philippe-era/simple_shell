#include "shell_prototype.h"

/**
 * bfree – sets free a pointer from the buffer
 * @pointer_check: address of the pointer to free
 * Return: 1 is set free.
 */
int bfree(void **pointer_check)
{
	int success = 1, fail = 0;
	if (pointer_check && *pointer_check)
	{
		free(*pointer_check);
		*pointer_check = NULL;
		return (success);
	}
	return (fail);
}
