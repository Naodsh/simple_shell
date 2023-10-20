#include "main.h"

/**
 * set_env - set an environment variable
 * @args: An array of arguments where args[1] is the variable name
 * and args[2] is the value
 *
 * Return: 0 on success, -1 on failure
 */
int set_env(char **args)
{
	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}
	if (setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}

/**
 * unset_env - unset an environment variable
 * @args: An array of arguments where args[1] is the variable name to unset
 *
 * Return: 0 on success, -1 on failure
 */
int unset_env(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return (-1);
	}
	if (unsetenv(args[1]) != 0)
	{
		perror("unsetenv");
		return (-1);
	}

	return (0);
}
