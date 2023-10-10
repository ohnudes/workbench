
void	sieve_candidates(int **from, int **to, int p)
{
	int	*output = *from;
	for (int *input = *from; input < *to; input++)
		if (*input % p != 0)
			*output++ = *input;
	*to = output;
}

int eratosthenes(int n, int buf[n - 2])
{
	for (int i = 2; i < n; i++)
		buf[i - 2] = i;

	int	*candidates = buf;
	int	*end = buf + n - 2;
	while (candidates < end)
	{
		int	p = *candidates++;
		sieve_candidates(&candidates, &end, p);
	}
	return (end - buf);
}
