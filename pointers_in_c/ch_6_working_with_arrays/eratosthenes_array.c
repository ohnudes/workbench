#include <stdio.h>

int	compact0(int n, int array[n])
{
	int	m;
	m = 0;

	for (int i = 0; i < n; i++)
		if (array[i] > 0)
			array[m++] = array[i];

	// printing array with values sorted
	for (int i = 0; array[i] < n - 2; i++)
		printf("buf[%d] = %d\n", i, array[i]);

	return (m);
}

int	eratosthenes(int n, int buf[n - 2])
{
	int i;

	for (i = 2; i < n; i++)
		buf[i - 2] = i;

	for (i = 0; i * i < n; i++)
	{
		if (buf[i] == 0) continue;
		int p = buf[i];
		for (int j = p * p; j < n; j+= p)
			buf[j - 2] = 0;
	}
	// printing content of array with only primes left
	for (i = 0; i < n - 2; i++)
		printf("buf[%d] = %d\n", i, buf[i]);

	printf(">> GOING INTO COMPACT <<\n");

	return (compact0(n - 2, buf));
}

int	main(void)
{
	int	n;
	int	array[100];

	n = 100;
	eratosthenes(n, array);
	return (0);
}
