#include "shell_prototype.h"

/**
 * hsh – number one shelled loop
 * @info: STRUCTURE CONTAINING NECESSARY INFO
 * @av: vector from main
 * Return: 0 on success
 */
int hsh(info_t *info, char **av)
{
	ssize_t read_line = 0;
	int build = 0, success = 0, stable = 1;

	while (read_line != -1 && build != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		read_line = get_input(info);
		if (read_line != -1)
		{
			set_info(info, av);
			build = find_builtin(info);
			if (build == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, success);
	}
	write_history(info);
	free_info(info, stable);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (build == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (build);
}

/**
 * find_builtin – built in command found
 * @info: Structure containing necessary info found
 * Return: returns -1 if build failed
 */
int find_builtin(info_t *info)
{
	int initial, build = -1;
	builtin_table build_array[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (initial = 0; build_array[initial].kind; initial++)
		if (_strcmp(info->argv[0], build_array[initial].kind) == 0)
		{
			info->line_err_count++;
			build = build_array[initial].func(info);
			break;
		}
	return (build);
}

/**
 * find_cmd – Path in the cmd
 * @info: Structure containing necessary info
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int initial, other_num;

	info->path = info->argv[0];
	if (info->linecount_pattern == 1)
	{
		info->line_err_count++;
		info->linecount_pattern = 0;
	}
	for (initial = 0, other_num = 0; info->arg[initial]; initial++)
		if (!is_delim(info->arg[initial], " \t\n"))
			other_num++;
	if (!other_num)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
					|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd – cmd to be executed
 * @info: Structure containing info necessary to run
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;
	int exit_cmd = 1;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, exit_cmd);
			if (errno == EACCES)
				exit(126);
			exit(exit_cmd);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
