#include "shell_prototype.h"

/**
 * _myenv - displays the current environment you in
 * @info: Structure with parameters needed
 * Return: Always 0 = success
 */
int _myenv(info_t *info)
{
	int success = 0;

	print_list_str(info->env);
	return (success);
}

/**
 * _getenv – returns value of the environment you in
 * @info: Structure with parameters needed
 * @name: variable name
 *
 * Return: the value checking
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *point;

	while (node)
	{
		point = starts_with(node->string_check, name);
		if (point && *point)
			return (point);
		node = node->next;
	}
	return (NULL);
}

/**
 * _myunsetenv – environment variable removed
 * @info: Structure with parameters needed
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int increment;
	int initial = 1;
	int success = 1;
	int final = 0;

	if (info->argc == success)
	{
		_eputs("Too few arguements.\n");
		return (success);
	}
	for (initial; initial <= info->argc; initial++)
		_unsetenv(info, info->argv[increment]);

	return (final);
}



/**
 * _mysetenv – declare environment variable
 * @info: Structure with parameters needed
 *  Return: Always 0 = success
 */

int _mysetenv(info_t *info)
{
	int success = 1;
	int otherwise = 0;

	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (success);
	}
	if (_setenv(info, info->argv[success], info->argv[2]))
		return (otherwise);
	return (success);
}


/**
 * populate_env_list - populates environment with linked list
 * @info: Structure with parameters needed
 * Return: Always 0 = success
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	int otherwise = 0;
	size_t initial;

	for (initial = 0; environ[initial]; initial++)
		add_node_end(&node, environ[initial], otherwise);
	info->env = node;
	return (otherwise);
}


