/*	Pointers in C programming: A Modern Approach to memory management,
 *	recursive data structures, strings and arrays.
 *	Thomas Mailund
 *
 *	Chapter 6: arrays and pointers.
 */

/*	Count sort with array
 *
 *	1.
 *	Create an array (buckets) with the total of possible chars and set it to '\0'
 *	2.
 *	Parse given array. The index of buckets is correspondant with char set to decimal.
 *	Increment the index value by the amount of occurrences in array[n]
 *	At this point: if the char is not in array[n], the index is set to '\0', else, a 1 or +
 *	3.
 *	Go throught buckets by its index. If the value of its content is > 0, set array[k] to correspondant char.
 *	Outer loop goes through buckets[256], checking if any value is true.
 *	Inner loop goes through array[n], equals its value to the occurence, and increments array index (k).
 */

#include <stdio.h>

void	sort_chars(int n, unsigned char array[n])
{
	int	buckets[256];
	int	i;

	i = 0;
	while (i < 256)
	{
		buckets[i] = 0;
		i++;
	}
	i = 0;
	while (i < n)
	{
		unsigned int bucket = array[i];
		buckets[bucket]++;
		i++;
	}
	int	k;
	int	j;
	k = 0;
	i = 0;
	while (i < 256)
	{
		j = 0;
		while (j < buckets[i])
		{
			array[k++] = (unsigned char)i;
			j++;
		}
		i++;
	}
}

int	main(void)
{
	unsigned char array[] = { 'f', 'o', 'o', 'b', 'a', 'r'};
	int	n = sizeof(array) / sizeof(*array);
	printf("%d\n", n);
	sort_chars(n, array);
	for (int i = 0; i < n; i++)
		printf("%c", array[i]);
	printf("\n");
	return (0);
}
