/* Alignment are guaranteed to be integral powers of 2.
 * In this case, it matches the size but is not guaranteed.
 * If an object can sit an any address, it will also align 
 * at higher addresses that are multiple of its sizeof() higher,
 * while also being possible to align at smaller sizes.
 */

#include <stdio.h>
#include <stdalign.h>

int	main(void)
{
	printf("chars align at %zu and have size %zu\n", alignof(char), sizeof(char));
	printf("int align at %zu and have size %zu\n", alignof(int), sizeof(int));
	printf("double align at %zu and have size %zu\n", alignof(double), sizeof(double));
	return (0);
}

/* Output:
 * chars align at 1 and have size 1
 * int align at 4 and have size 4
 * double align at 8 and have size 8
 */
