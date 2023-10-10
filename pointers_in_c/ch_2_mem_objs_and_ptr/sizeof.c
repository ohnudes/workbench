/* Guaranteed by the C standard:
 * CHAR size is of 1 byte, the rest is up to architecture.
 * More accurate: 1 char is 8 bits, but this is not guaranteed.
 * To check with const macro CHAR_BIT.
 *
 * All sizes depend of CHAR size.
 */

#include <limits.h>
#include <stdio.h>

int	main(void)
{
	char	c;
	printf("c: %zu		%zu\n", sizeof(char), sizeof(c));

	int		i;
	printf("i: %zu		%zu\n", sizeof(int), sizeof(i));

	double	d;
	printf("d: %zu		%zu\n", sizeof(double), sizeof(d));

	printf("CHAR_BIT:	%d\n", CHAR_BIT);
	return (0);
}

/*	output:
 *	c: 1            1
 *	i: 4            4
 *	d: 8            8
 */
