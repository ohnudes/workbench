/* Akin to union type, but differences:
 * Even tho it uses 13 bytes, it allocates a block of 16.
 * This is because of **padding**, which respects the order of
 * the variables declared, + the alignment, which is explained at the index.
 *
 * For reasons explained at [[allignof.c]], the rule for structs
 * is that the components must come in order. If this results with 
 * extra unused space after first char, in case of an struct array,
 * the next value will be located next to the first memory address.
 */

#include <stdio.h>

struct	data2
{
	int		i;
	double	d;
	char	c;
};

struct	data
{
	char	c;
	int		i;
	double	d;
};

int	main(void)
{
	struct data	data;
	printf("sizeof data ==	%zu\n", sizeof(data));
	printf("max size of components == %zu\n", sizeof(data.c) + sizeof(data.i) + sizeof(data.d));

	printf("data	at	%p\n", (void *)&data);
	printf("data.c	at	%p\n", (void *)&data.c);
	printf("data.i	at	%p\n", (void *)&data.i);
	printf("data.d	at	%p\n", (void *)&data.d);

	printf("\n");

	struct data2	data2;
	printf("sizeof data ==	%zu\n", sizeof(data2));
	printf("max size of components == %zu\n", sizeof(data2.c) + sizeof(data.i) + sizeof(data.d));

	printf("data	at	%p\n", (void *)&data2);
	printf("data.c	at	%p\n", (void *)&data2.c);
	printf("data.i	at	%p\n", (void *)&data2.i);
	printf("data.d	at	%p\n", (void *)&data2.d);

	return (0);
}

/* Output:
 * struct: char - int - double
 * sizeof data ==  16
 * max size of components == 13
 * data    at      0x7ffc18a60770
 * data.c  at      0x7ffc18a60770
 * data.i  at      0x7ffc18a60774
 * data.d  at      0x7ffc18a60778
 *
 * struct: int - double - char
 * sizeof data ==  24
 * max size of components == 13
 * data    at      0x7ffc18a60780
 * data.c  at      0x7ffc18a60790
 * data.i  at      0x7ffc18a60780
 * data.d  at      0x7ffc18a60788
 */
