#include "shell_prototype.h"

/**
 * _myhistory –Shows the past code changes
 * @info:Structure contains the parameters needed
 *  Return: Success = Always being 0
 */
int _myhistory(info_t *info)
{
	int success = 0;

	print_list(info->history_node);
	return (success);
}
/**
 * unset_alias – String will be aliased
 * @info: structure containing the parametrs needed for the arguement
 * @str: the aliased string
 * Return: Success = 0 , fail = -1
 */
int unset_alias(info_t *info, char *str)
{
	char *point, charac_start;
	int fail = -1;
	int success = 0;
	int final;

	point = _strchr(str, '=');
	if (!point)
		return (1);
	charac_start = *point;
	*point = success;
	final = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, fail)));
	*point = charac_start;
	return (final);
}

/**
 * set_alias – String to set as alias
 * @info: structure containing necessary arguements
 * @str: the alias string
 *
 * Return: Success = 0 , fail otherwise
 */
int set_alias(info_t *info, char *str)
{
	char *point;
	int otherwise = 1;
	int success = 0;

	point = _strchr(str, '=');
	if (!point)
		return (otherwise);
	if (!*++point)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, success) == NULL);
}

/**
 * print_alias – displays alias string
 * @node: the node to be aliased
 *
 * Return: Success on 0 , otherwise
 */
int print_alias(list_t *node)
{
	char *point = NULL, *initial = NULL;
	int otherwise = 1;
	int success = 0;

	if (node)
	{
		point = _strchr(node->string_check, '=');
		for (initial = node->string_check; initial <= point; initial++)
		_putchar(*initial);
		_putchar('\'');
		_puts(point + otherwise);
		_puts("'\n");
		return (success);
	}
	return (otherwise);
}

/**
 * _myalias – replica of man alias
 * @info: Structure containing parameters necessary for this function
 *  Return: Always 0 if succesful
 */
int _myalias(info_t *info)
{
	int success = 0;
	int initial = 1;
	char *point = NULL;
	list_t *node = NULL;

	if (info->argc == initial)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (success);
	}
	for (initial = 1; info->argv[initial]; initial++)
	{
		point = _strchr(info->argv[initial], '=');
		if (point)
			set_alias(info, info->argv[initial]);
		else
			print_alias(node_starts_with(info->alias, info->argv[initial], '='));
	}

	return (success);
}


