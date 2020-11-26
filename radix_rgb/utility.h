#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <stdio.h>
#include <stdlib.h>

#include "mask.h"

typedef unsigned short ushort;

void printArray(ushort arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);

    printf("\n");
}

ushort *gen_random_rgb_arr(int size)
{
    int rgb_max = 1 << 8*sizeof(ushort);
    ushort *arr = (ushort *)malloc(sizeof(ushort) * size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = rand() % rgb_max;
    }
    return arr;
}

#endif