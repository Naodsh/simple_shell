#include "main.h"

/**
 * main - start of function
 * @argc: number of argument
 * @args: an array string arguments
 *
 * Return: an intiger
 */
int main(int argc, char *args[])
{
	int fd = STDIN_FILENO;

	if (isatty(fd) == 1)
		shell_interactive(args[argc - 1]);
	else
		shell_non_interactive(args[argc - 1]);

	return (0);
}
