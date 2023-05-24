#include "shell_prototype.h"


/**
 * clear_info - declares info_tfor later use
 * @info: Structure address contaoinging necessary info
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}


/**
 * set_info – declares the structure
 * @info: Structure with memory address
 * @av: argument vector for this program:
 */
void set_info(info_t *info, char **av)
{
	int initial = 0, first_num = 1, second_num = 0;

	info->file_name = av[second_num];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{
			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[second_num] = _strdup(info->arg);
				info->argv[first_num] = NULL;
			}
		}
		for (initial = 0; info->argv && info->argv[initial]; initial++)
			;
		info->argc = initial;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info – set free the info
 * @info: Struct with the memory address
 * @all: frees all fields
 */
void free_info(info_t *info, int all)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (all)
	{
		if (!info->cmd_buffer)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history_node)
			free_list(&(info->history_node));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buffer);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}


