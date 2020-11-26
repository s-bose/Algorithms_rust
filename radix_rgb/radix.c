#include <stdio.h>
#include <stdlib.h>


#include "mask.h"
#include "utility.h"

void count_sort(unsigned short arr[], int n, color c)
{
    unsigned short output[n];
    int _size;
    switch(c)
    {
        case B:
        case R:
            _size = 1 << 5;     // 1 << 5 = 2^5 = 32
        case G:
            _size = 1 << 6;
    }

    int count[_size];
    for (int i = 0; i < _size; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
    {
        // extract the color value from each element
        unsigned short val = mask(arr[i], c);
        count[val]++;
    }

    for (int i = 1; i < _size; i++)
        count[i] += count[i-1];

    int i = n - 1;
    while (i >= 0)
    {
        unsigned short index = mask(arr[i], c);
        output[count[index] - 1] = arr[i];
        count[index]--;
        i--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radix_sort(unsigned short arr[], int n)
{
    for (int i = 0; i < 3; i++)
        count_sort(arr, n, i);
}



int main() 
{
    int size = 10;
    ushort *arr = gen_random_rgb_arr(size);
    printf("%s\n", "original array: ");
    printArray(arr, size);

    print_RGB_Val(arr, size, R);
    printf("%s\n", "rgb array sorted according to r");
    count_sort(arr, size, R);

    printArray(arr, size);

    print_RGB_Val(arr, size, R);


    
    
    return 0;
}