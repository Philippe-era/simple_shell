#include "shell_prototype.h"


/**
 * add_node_end – inserts a node to the list
 * @header_look: location of pointer
 * @string_check: field node containing strings
 * @number_check: numbers to be checked
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **header_look, const char *string_check, int number)
{
	list_t *node_new, *node_check;

	if (!header_look)
		return (NULL);

	node_check = *header_look;
	node_new = malloc(sizeof(list_t));
	if (!node_new)
		return (NULL);
	_memset((void *)node_new, 0, sizeof(list_t));
	node_new->number = number;
	if (string_check)
	{
		node_new->string_check = _strdup(string_check);
		if (!node_new->string_check)
		{
			free(node_new);
			return (NULL);
		}
	}
	if (node_check)
	{
		while (node_check->next)
			node_check = node_check->next;
		node_check->next = node_new;
	}
	else
		*header_look = node_new;
	return (node_new);
}

/**
 * print_list_str – displays the elements
 * @hat_look: the first node to be checked
 *
 * Return: length of pointer
 */
size_t print_list_str(const list_t *hat_look)
{
	size_t initial = 0;

	while (hat_look)
	{
		_puts(hat_look->string_check ? hat_look->string_check : "(nil)");
		_puts("\n");
		hat_look = hat_look->next;
		initial++;
	}
	return (initial);
}

/**
 * delete_node_at_index – removes the node from list
 * @header_look: location of pointer to be checked
 * @number_count: number count of node
 * Return: 1 success
 */
int delete_node_at_index(list_t **header_look, unsigned int number_count)
{
	list_t *node_first, *previos_node;
	int success = 0, otherwise = 1;
	unsigned int initial = 0;

	if (!header_look || !*header_look)
		return (success);

	if (!number_count)
	{
		node_first = *header_look;
		*header_look = (*header_look)->next;
		free(node_first->string_check);
		free(node_first);
		return (otherwise);
	}
	node_first = *header_look;
	while (node_first)
	{
		if (initial == number_count)
		{
			previos_node->next = node_first->next;
			free(node_first->string_check);
			free(node_first);
			return (otherwise);
		}
		initial++;
		previos_node = node_first;
		node_first = node_first->next;
	}
	return (success);
}

/**
 * free_list – removes the next
 * @header_pointer: location of next node
 * Return: void
 */
void free_list(list_t **head_pointer)
{
	list_t *node_look, *node_next, *header_look;

	if (!head_pointer || !*head_pointer)
		return;
	header_look = *head_pointer;
	node_look = header_look;
	while (node_look)
	{
		node_next = node_look->next;
		free(node_look->string_check);
		free(node_look);
		node_look = node_next;
	}
	*head_pointer = NULL;
}

/**
 * add_node – inserts a node in the list
 * @head: location of the head node
 * @str_check: string to be checked
 * @num: index of number
 *
 * Return: size of list
 */
list_t *add_node(list_t **header_look, const char *string_check, int number)
{
	list_t *header_point;
	int success = 0;

	if (!header_look)
		return (NULL);
	header_point = malloc(sizeof(list_t));
	if (!header_point)
		return (NULL);
	_memset((void *)header_point, success, sizeof(list_t));
	header_point->number = number;
	if (string_check)
	{
		header_point->string_check = _strdup(string_check);
		if (!header_point->string_check)
		{
			free(header_point);
			return (NULL);
		}
	}
	header_point->next = *header_look;
	*header_look = header_point;
	return (header_point);
}
