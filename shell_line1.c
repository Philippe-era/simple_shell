#include "shell.h"

/**
 * _setenv – declares an environmental variable or changes it
 * @info: Structure containing parameters necessary
 * @var: variable property
 * @value:environment value
 *  Return: Success = 0 ;
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buffer = NULL;
	list_t *node;
	int constant_num = 1;
	int success = 0;
	char *point;

	if (!var || !value)
		return (success);

	buffer = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buffer)
		return (constant_num);
	_strcpy(buffer, var);
	_strcat(buffer, "=");
	_strcat(buffer, value);
	node = info->env;
	while (node)
	{
		point = starts_with(node->str, var);
		if (point && *point == '=')
		{
			free(node->str);
			node->str = buffer;
			info->env_changed = consant_num;
			return (success);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buffer, success);
	free(buffer);
	info->env_changed = constant_num;
	return (success);
}

/**
 * _unsetenv – deletes the environment variable
 * @info: Structure containing parameters necessary
 *  Return: 1 delete otherwise fail
 * @var: environment property
 */
int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t initial = 0;
	int success = 0;
	char *point;

	if (!node || !var)
		return (success);

	while (node)
	{
		point = starts_with(node->str, var);
		if (point && *point == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), intial);
			initial = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		initial++;
	}
	return (info->env_changed);
}
/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing parameters needed 
 * Return: Always 0 sucess
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		int success = 0;

		info->environ = list_to_strings(info->env);
		info->env_changed = success;
	}

	return (info->environ);
}
