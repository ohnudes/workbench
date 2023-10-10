/* Int is of sizeof(int), so an array of 5, will 5 * sizeof(int)
 * Array implies contiguous memory. 
 * It can be iterated with an index, but when using pointer 
 * arithmetics, be carefull of using a value that will iterate with
 * the correspondant size, such in a way that the memory value will increment
 * by the sizeof(type), rather than +1.
 */

#include <inttypes.h>
#include <stdio.h>

int	main(void)
{
	int	array[5];
	printf("	array	==	%p\n", (void *)array);

	for (int i = 0; i < 5; i++)
		printf("&array[%d]	==	%p\n", i, (void *)&array[i]);

	printf("sizeof array	==	%zu\n", sizeof(array));
	printf("5 * sizeof(int)	==	%zu\n", 5 * sizeof(int));

	return (0);
}

/* Output
 *         array   ==      0x7ffd03d7a7f0
 * &array[0]       ==      0x7ffd03d7a7f0
 * &array[1]       ==      0x7ffd03d7a7f4
 * &array[2]       ==      0x7ffd03d7a7f8
 * &array[3]       ==      0x7ffd03d7a7fc
 * &array[4]       ==      0x7ffd03d7a800
 * sizeof array    == 20
 * 5 * sizeof(int) == 20
 */

