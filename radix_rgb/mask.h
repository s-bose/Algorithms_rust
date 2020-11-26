#ifndef _MASK_H_
#define _MASK_H_

#include <stdio.h>

typedef enum _color
{
    R, 
    G, 
    B
} color;
 
typedef unsigned short ushort;

ushort mask(ushort num, color c)
{
    ushort mask_b = 31;
    ushort mask_g = ((31 << 1) + 1) << 5;
    ushort mask_r = (31 << 11);
    switch(c)
    {
        case B:
            return num & mask_b; 
        case G:
            return (num & mask_g) >> 5;
        case R:
            return (num & mask_r) >> 11;
    }
}

void print_RGB_Val(ushort arr[], int n, color c)
{
    printf("%c value of each element: \n", c == R ? 'R' : c == G ? 'G' : 'B');
    for (int i = 0; i < n; i++)
        printf("%d, ", mask(arr[i], c));
    printf("\n");
}

#endif