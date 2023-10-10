/* The reason for %p as (void *) is because it's what
 * is actually asked.
 * In the example, the double is the first one in mem
 * order. This is not a given, could change with optimiz
 * options. Individual variables will be stored by compiler
 * optimization logic, so there's no assumption of order to 
 * be made.
 * Keep in mind: some architectures will not necessarily 
 * order the memory consecutivel, incrementaly, but in reverse as well.
 */

#include <stdio.h>

int	main(void)
{
	char	c = 1;
	printf("c: %d		%p\n", c, (void *)&c);

	int	i = 2;
	printf("i: %d		%p\n", i, (void *)&i);

	double	d = 3;
	printf("d: %f	%p\n", d, (void *)&d);
	return (0);
}

/* Output
 *
 * c: 1            1
 * i: 4            4
 * d: 8            8
 */
