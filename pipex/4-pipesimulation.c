
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int ac, char *av[], char *env[])
{
	char	*arg[] = {"bin/ls", NULL};
	int		fd[2];
	int		pid1; // cmd1
	int		pid2; // cmd2

	if (pipe(fd) == -1)
		return 1;
	pid1 = fork();
	if (pid1 == -1)
		return 2;
	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/bin/ls", arg, env);
	}
	else
		pid2 = fork();
	waitpid(pid1, NULL, 0);

	return (0);
}
