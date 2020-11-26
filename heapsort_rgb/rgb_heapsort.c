#include <stdio.h>
#include <stdlib.h>

#include"comparison.h"
#include "mask.h"

void swap(unsigned short *a, unsigned short *b)
{
    unsigned short temp = *a;
    *a = *b;
    *b = temp;
}

float greyscale(unsigned short rgb)
{
    unsigned short Red, Green, Blue;
    Red = mask(rgb, R);
    Green = mask(rgb, G);
    Blue = mask(rgb, B);
    return (0.3 * Red) + (0.59 * Green) + (0.11 * Blue); 
}

void max_heapify(unsigned short rgb_arr[], int n, int idx)
{
    int max = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (
        (left < n) && 
        isGreater(
            greyscale(rgb_arr[left]), 
            greyscale(rgb_arr[max])
        ))
        max = left;

    if (
        (right < n) &&
        isGreater(
            greyscale(rgb_arr[right]),
            greyscale(rgb_arr[max])
        ))
        max = right;

    if (max != idx)
    {
        swap(&rgb_arr[idx], &rgb_arr[max]);
        max_heapify(rgb_arr, n, max);
    }
}

void heapSort(unsigned short rgb_arr[], int n)
{
    for (int i = n/2 - 1; i >= 0; i--)
        max_heapify(rgb_arr, n, i);

    for (int j = n-1; j > 0; j--)
    {
        swap(&rgb_arr[0], &rgb_arr[j]);
        max_heapify(rgb_arr, j, 0);
    }
}

void printArray(unsigned short arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d, ", arr[i]);

    printf("\n");
}

void printArrayGrey(unsigned short arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%f, ", greyscale(arr[i]));

    printf("\n");
}


int main()
{
    int rgb_max = 1 << 8*sizeof(unsigned short);
    unsigned short arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % rgb_max;
    }
    printf("%s\n", "Original rgb array");

    printArray(arr, 10);

    heapSort(arr, 10);    

    printf("%s\n", "greyscale array: ");
    
    printArrayGrey(arr, 10);

    return 0;
}

