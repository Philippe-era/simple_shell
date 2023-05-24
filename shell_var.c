#include "shell_prototype.h"

/**
 * is_chain – checks if it is a buffer
 * @info: Structure containing necessary parameters
 * @buf: the char buffer
 * @p: location of buffer pointer
 *
 * Return: 1 is success.
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t join = *p;
	int num_track = 1;
	int num_stable = 0;

	if (buf[join] == '|' && buf[join + num_track] == '|')
	{
		buf[join] = num_stable;
		join++;
		info->cmd_buffer_type = CMD_OR;
	}
	else if (buf[join] == '&' && buf[join + num_track] == '&')
	{
		buf[join] = num_stable;
		join++;
		info->cmd_buffer_type = CMD_AND;
	}
	else if (buf[join] == ';')
	{
		buf[join] = num_stable;
		info->cmd_buffer_type = CMD_CHAIN;
	}
	else
		return (num_stable);
	*p = join;
	return (num_track);
}

/**
 * replace_alias – changes token var
 * @info: structure containing necessary info
 *
 * Return: 1 if success
 */
int replace_alias(info_t *info)
{
	int initial, success = 0, num_check = 1;
	list_t *node_check;
	char *point;

	initial = 0;
	for (initial = 0; initial < 10; initial++)
	{
		node_check = node_starts_with(info->alias, info->argv[0], '=');
		if (!node_check)
			return (success);
		free(info->argv[success]);
		point = _strchr(node_check->string_check, '=');
		if (!point)
			return (success);
		point = _strdup(point + num_check);
		if (!point)
			return (success);
		info->argv[0] = point;
	}
	return (1);
}

/**
 * replace_vars – changes the variable
 * @info: Structure containing necessary
 * Return: 1 success
 */
int replace_vars(info_t *info)
{
	int initial = 0, num_track = 1, success = 0;
	list_t *node_check;

	for (initial = 0; info->argv[initial]; initial++)
	{
		if (info->argv[initial][0] != '$' || !info->argv[initial][num_track])
			continue;

		if (!_strcmp(info->argv[initial], "$?"))
		{
			replace_string(&(info->argv[initial]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[initial], "$$"))
		{
			replace_string(&(info->argv[initial]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node_check = node_starts_with(info->env, &info->argv[initial][1], '=');
		if (node_check)
		{
			replace_string(&(info->argv[initial]),
					_strdup(_strchr(node_check->string_check, '=') + 1));
			continue;
		}
		replace_string(&info->argv[initial], _strdup(""));

	}
	return (success);
}

/**
 * replace_string – changes string
 * @old: old string dirty sting
 * @new: clean string
 *
 * Return: 1 if succesful
 */
int replace_string(char **old, char *new)
{
	int replace = 1;

	free(*old);
	*old = new;
	return (replace);
}


/**
 * check_chain - checks we should continue chaining based on last status
 * @info: Struct containing necessary info
 * @buf: character buffer
 * @p: location of pointer
 * @i: initial point
 * @len: counts char in buf
 Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t join = *p;

	if (info->cmd_buffer_type == CMD_AND)
	{
		if (info->status)
		{
			int success = 0;

			buf[i] = success;
			join = len;
		}
	}
	if (info->cmd_buffer_type == CMD_OR)
	{
		if (!info->status)
		{
			int success = 0;

			buf[i] = success;
			join = len;
		}
	}

	*p = join;

}















