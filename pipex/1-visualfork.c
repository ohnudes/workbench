
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int	main(int argc, char *argv[])
{
	int	id;
	int	n;

	id = fork();
	if (id == 0)//child process
		n = 1;
	else//parent
		n = 6;
	if (id != 0)//waits for child process to end
		wait(NULL);//parent returns before child process

	int	i;
	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}
	if (id != 0)
		printf("\n");
	return (0);
}
/* OUTPUT */
/* normal output:
 * 1 2 3 4 5 6 7 8 9 10
 *
 * commented wait lines:
 * 6 7 8 9 10 
 * 1 2 3 4 5 *
 *
 */
