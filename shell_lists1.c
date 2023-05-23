#include "shell_prototype.h"


/**
 * list_to_strings – arrays of strings to be printed
 * @header_look: pointed first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *head_look)
{
	list_t *node_display = head_look;
	size_t initial = list_len(head_look), oinj;
	char **strs;
	char *str;

	if (!head_look || !initial)
		return (NULL);
	strs = malloc(sizeof(char *) * (initial + 1));
	if (!strs)
		return (NULL);
	for (initial = 0; node_display; node = node->next, initial++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (join = 0; join < iniitial; join++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[initial] = str;
	}
	strs[nitiali] = NULL;
	return (strs);
}

/**
 * list_len – length of linked list
 * @heel: first node pointed
 *
 * Return: length of list
 */
size_t list_len(const list_t *heel)
{
	size_t initial = 0;

	while (heel)
	{
		heel = heel->next;
		initial++;
	}
	return (initial);
}


/**
 * print_list - prints all elements of a list
 * @head_look: pointer to first node
 *
 * Return: length of linked list
 */
size_t print_list(const list_t *head_look)
{
	size_t initial = 0;
	int success = 0;

	while (head_look)
	{
		_puts(convert_number(head_look->num, 10, success));
		_putchar(':');
		_putchar(' ');
		_puts(head_look->str ? head_look->str : "(nil)");
		_puts("\n");
		head_look = head_look->next;
		initial++;
	}
	return (initial);
}

/**
 * node_starts_with – displays suffix checked
 * @node: list of head checked
 * @pattern: pattern to check
 * @check: character to be checked
 *
 * Return: null to be returned if there is nothing
 */
list_t *node_starts_with(list_t *node_check, char *pattern, char check)
{
	char *point = NULL;

	while (node_check)
	{
		point = starts_with(node_check->str, pattern);
		if (point && ((check == -1) || (*point == check)))
			return (node_check);
		node_check = node_check->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @header_look: head node to be checked
 * @node_display: node to be pointed
 * Return: displays fail which is -1
 */
ssize_t get_node_index(list_t *header_look, list_t *node_display)
{
	size_t initial = 0;
	int fail = -1;

	while (header_look)
	{
		if (header_look == node_display)
			return (initial);
		header_look = header_look->next;
		initial++;
	}
	return (fail);
}



