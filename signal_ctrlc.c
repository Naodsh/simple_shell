#include "main.h"

/**
 * handle_ctrlc - ignore Ctrl-C input and prints prompt again
 * @n: takes in int from signal
 */
void handle_ctrlc(int n)
{
	(void)n;
	write(STDOUT_FILENO, "\n$ ", 3);
}
