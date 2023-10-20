#include "main.h"


/**
 * execute_cmd - check if builtin or system call
 * @argv: tokens
 * @name: program name
 *
 * Return: an integer success or failure
 */
int execute_cmd(char **argv, char *name)
{
	unsigned long int ind;
	built_in built_in_list[] = {
		{"exit", exit_f},
		{"env", env_f},
		{"cd", cd_f},
		{"setenv", set_env},
		{"unsetenv", unset_env}
	};

	if (!argv)
	{
		return (-1);
	}

	for (ind = 0; ind < sizeof(built_in_list) /
			sizeof(built_in); ind++)
	{
		if (strcmp(argv[0], built_in_list[ind].name) == 0)
		{
			return (built_in_list[ind].func(argv));
		}
	}

	return (sys_call(argv, name));
}
