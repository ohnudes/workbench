#include "./easy_vars.h"

int main(void)
{
    t_integers  my_int[integers_array_len];
    
    my_int[i] = 1;
    my_int[j] = 2;
    my_int[sum] = my_int[i] + my_int[j];

    printf("%d + %d = %d\n", my_int[i], my_int[j], my_int[sum]);

    my_int[k] = 0;
    my_int[max] = 10;
    my_int[total] = 0;
    while (my_int[k] < my_int[max])
        my_int[total] += my_int[k]++;
    
    printf("Sumatoria de my_int[k] a my_int[max] = %d\n", my_int[total]);

    my_int[end] = 123;
    printf("Ejecutar 'echo $?' para ver el exit code\n");
    return (my_int[end]);
}