#ifndef _COMPARISON_H_
#define _COMPARISON_H_

#define EPSILON 1e-9

int isEqual(float lhs, float rhs)
{
    return ((lhs - rhs) < EPSILON) && ((rhs - lhs) < EPSILON); 
}

int isGreater(float lhs, float rhs)
{
    return (lhs > rhs) + EPSILON;
}

int isLesser(float lhs, float rhs)
{
    return (lhs < rhs) + EPSILON;
}

#endif