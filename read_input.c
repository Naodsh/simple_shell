#include "main.h"
/**
 * read_input - reads input
 *
 * Return: string read
 */
char *read_input(void)
{
	int character, buffer = BUFF;
	int i = 0;
	char *line = malloc(sizeof(char) * buffer);

	if (line == NULL)
	{
		perror("allocation error in read");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar();
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
			line[i] = character;
		i++;

		if (i >= buffer)
		{
			buffer += buffer;
			line = realloc(line, buffer);
			if (line == NULL)
			{
				perror("reallocation error in read");
				exit(EXIT_FAILURE);
			}
		}
	}
}
