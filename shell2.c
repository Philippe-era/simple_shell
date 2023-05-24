#include "shell_prototype.h"

/**
 * _myexit – closes the shell
 * @info: contains the necessary information
 * Return: returns exit if exit is succesful
 */
int _myexit(info_t *info)
{
	int close_shell;
	int fail = -1;
	int success = 1;
	int new_status = 2;

	if (info->argv[1])
	{
		close_shell = _erratoi(info->argv[1]);
		if (close_shell == fail)
		{
			info->status = new_status;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (success);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-new_status);
	}
	info->err_num = fail;
	return (-new_status);
}

/**
 * _mycd – moves to different directory
 * @info: parameters that will be maintained
 * Return: Always the number 0 will be returned
 */
int _mycd(info_t *info)
{
	char *status, *direct, success = 1, fail = -1, buffer[1024];
	int directory_retun;

	status = getcwd(buffer, 1024);
	if (!status)
		_puts("TODO: >>getcwd failure returns error message here<<\n");
	if (!info->argv[1])
	{
		direct = _getenv(info, "HOME=");
		if (!direct)
			directory_retun =
				chdir((direct = _getenv(info, "PWD=")) ? direct : "/");
		else
			directory_retun = chdir(direct);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(status);
			_putchar('\n');
			return (success);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		directory_retun =
			chdir((direct = _getenv(info, "OLDPWD=")) ? direct : "/");
	}
	else
		directory_retun = chdir(info->argv[1]);
	if (directory_retun == fail)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp – moves to a different directory
 * @info: structure containing information required for this parameter
 * Return: Always Success
 */
int _myhelp(info_t *info)
{
	int success = 0;
	char **argument_array;

	argument_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (success)
		_puts(*argument_array);
	return (success);
}
