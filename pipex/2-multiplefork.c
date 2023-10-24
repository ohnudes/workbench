
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	msg(int	id1, int id2)
{
	printf("process ended		%d	%d\n", id1, id2);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	id1;
	int id2;
	
	id1 = fork();//w(n)/x(0)
	id2 = fork();//w(n)/x(0)(n)/y(0)(0)\w(n)(n)/z(0)
	if (id1 == 0)
	{
		if (id2 == 0)
			printf("this is process y(0/0)\n");
		else
			printf("this is process x(0/n)\n");
	}
	else
	{
		if (id2 == 0)
			printf("this is process z(n/0)\n");
		else
			printf("this is process w(n/n) <- parent\n");
	}
	while(wait(NULL) != -1 || errno != ECHILD)
		printf("process waiting		%i	%i\n", id1, id2);
	return (msg(id1, id2));
}
