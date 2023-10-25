/* Communicating between pipes: passing variable from 1 child to the parent
 * throught their FD
 */

#include <stdio.h>
#include <unistd.h>

int	factorial(int y)
{
	if (y - 1 > 0)
		y = y * factorial(y - 1);
	return (y);
}

int	main(int ac, char *av[], char *env[])
{
	int	fd[2];
	int	pid;
	
	if (pipe(fd) == -1)
		return 1;
	pid = fork();
	if (pid == -1)
		return 2;
	if (pid == 0)
	{
		close(fd[0]);
		int	x;
		printf("Input a number: ");
		scanf("%d", &x);
		if (write(fd[1], &x, sizeof(x)) == -1)
			return 5;
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int	y;
		if (read(fd[0], &y, sizeof(y)) == -1)
			return 4;
		y = factorial(y);
		close(fd[0]);
		printf("factorial from input: %d\n", y);
	}
	return (0);
}
