
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int agrc, char *argv[])
{
	int	arr[] = { 1, 2, 3, 4, 1, 2, 7 };
	int arr_size = sizeof(arr) / sizeof(*arr);
	int	start;
	int	end;
	int	id;
	int	fd[2];
	
	/* piping and forking safely */
	if (pipe(fd) == -1)
		return 1;
	id = fork();
	if (id == -1)
		return 2;

	/* assigning different indexes from the array to each fork */
	if (id == 0)
	{
		start = 0;
		end = arr_size / 2;
	}
	else
	{
		start = arr_size / 2;
		end = arr_size;
	}

	/* sum each element from their corresponding index*/
	int sum = 0;
	int	i;
	i = start;
	sum = 0;
	while (i < end)
	{
		sum += arr[i];
		i++;
	}
	printf("partial sum	%d\npid		%d\n", sum, id);
	if (id == 0)
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
			return 3;
		close(fd[1]);
	}
	else
	{
		int	sum_from_child;
		close(fd[1]);
		if (read(fd[0], &sum_from_child, sizeof(sum_from_child)) == -1)
			return 4;
		close(fd[0]);

		int	total_sum = sum + sum_from_child;
		printf("total sum	%d\n", total_sum);
		wait(NULL);
	}
	return (0);
}
