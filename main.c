#include "main.h"

/**
 * main - start of function
 * @argc: number of argument
 * @args: an array string arguments
 *
 * Return: an intiger
 */
int main(int argc, char *argv[])
{
	if (argc == 2)
	{

		shell_non_interactive(argv[0], argv[1]);
	}
	else if (argc == 1)
	{

		shell_interactive(argv[0]);
	}
	else
	{
		printf("Usage: %s [input_file]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	return (0);
}
