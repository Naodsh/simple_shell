#include "main.h"

/**
 * access_cmd - access command
 * @full_path: path to system call
 * @args: arguments
 *
 * Return: intiger
 */
int access_cmd(char *full_path, char **args)
{

	pid_t pid, ended_pid;
	int status, execve_status;

	pid = fork();
	if (pid == 0)
	{
		execve_status = execve(full_path, args, environ);
		if (execve_status == -1)
		{
			return (-1);
		}
	}
	else if (pid > 0)
	{
		ended_pid = waitpid(pid, &status, WUNTRACED);
		if (ended_pid == -1)
		{
			perror("error waiting for the child process to end");
			return (-1);
		}
	}
	else
	{
		perror("fork failed");
		return (-1);
	}

	return (-1);
}
