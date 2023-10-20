#include "main.h"
/**
 * cd_f - changes the working directory and updates PWD
 * @args: directory
 *
 * Return: 0 on success, -1 on failure
 */
int cd_f(char **args)
{
	if (args[1] == NULL)
	{
		perror("argument expected to cd\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("error: changing dir\n");
		}
	}

	return (1);
}

/**
 * exit_f - exit
 * @args: arguments
 *
 * Return: an interger
 */
int exit_f(char **args)
{
	if (args[1])
	{
		return (atoi(args[1]));
	}
	else
	{
		return (0);
	}
}

/**
 * env_f - env function
 * @args: argument
 *
 * Return: an integer
 */
int env_f(char **args)
{
	int i = 0;

	args = environ;
	while (args[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (-1);
}
