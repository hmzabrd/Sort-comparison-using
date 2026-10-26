#include <stdlib.h>
#include "generate.h"

int random_number(void)
{
    return (rand() % 32768) * 32768 + rand() % 32768;
}

int *generate_array(long n)
{
    long i;
    int *arr = malloc(sizeof(int) * n);

    if (arr == NULL)
        return NULL;

    for (i = 0; i < n; i++)
        arr[i] = random_number();

    return arr;
}

int *grow_array(int *arr, long old_n, long new_n)
{
    long i;
    int *bigger = realloc(arr, sizeof(int) * new_n);

    if (bigger == NULL)
        return NULL;

    for (i = old_n; i < new_n; i++)
        bigger[i] = random_number();

    return bigger;
}
