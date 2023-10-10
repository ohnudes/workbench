/* Union type takes the largest data type that it holds,
 * allocates for its size, and references every other kind
 * of type at the same address, so the data variable can be
 * treated as any type it holds.
 * In sum: it can store data in the same memory block and at 
 * the same address.
 */

#include <stdio.h>

union	data
{
	char	c;
	int		i;
	double	d;
};

#define MAX(a,b) (((a)>(b))?(a): (b))
#define MAX3(a,b,c) MAX((a),MAX((b), (c)))

int	main(void)
{
	union data	data;

	printf("sizeof data ==	%zu\n", sizeof(data));
	printf("max size of components == %zu\n", MAX3(sizeof data.c, sizeof data.i, sizeof data.d));

	printf("data	at	%p\n", (void *)&data);
	printf("data.c	at	%p\n", (void *)&data.c);
	printf("data.i	at	%p\n", (void *)&data.i);
	printf("data.d	at	%p\n", (void *)&data.d);

	return (0);
}

/* Output:
 * sizeof data ==  8
 * max size of components == 8
 * data    at      0x7ffd67c0b840
 * data.c  at      0x7ffd67c0b840
 * data.i  at      0x7ffd67c0b840
 * data.d  at      0x7ffd67c0b840
 */
