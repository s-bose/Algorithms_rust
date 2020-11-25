#ifndef _UTILITIES_H_
#define _UTILITIES_H_

#include <stdio.h>
#include <stdlib.h>

#include "marksheet.h"

#define NUM_SUBJ 5

int *generate_random_marks()
{
    int* marks = (int *)malloc(sizeof(int) * NUM_SUBJ);
    for (int i = 0; i < 5; i++)
        marks[i] = rand() % 100;

    return marks;
}

int *generate_subject_idx()
{
    int *idxes = (int *)malloc(sizeof(int) * NUM_SUBJ);
    for (int i = 0; i < 5; i++)
        idxes[i] = i;

    return idxes;
}


int total_marks(Student *student)
{
    int sum = 0;
    for (int i = 0; i < 5; ++i)
        sum += student->marks[i];
    return sum;
}

void shuffle(UniversityMarksheet *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          UniversityMarksheet tmp = array[j];
          array[j] = array[i];
          array[i] = tmp;
        }
    }
}

#endif