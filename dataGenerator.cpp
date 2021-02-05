#include "dataGenerator.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::string;

//typecasting because alloc returns a void pointer

int *intArray(int size)
{
    int *p = (int *)alloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1;
    }
    return p;
}
double *doubleArray(int size)
{
    double *p = (double *)alloc(size * sizeof(double));
    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1;
    }
    return p;
}

int *arrayOfOddIntegers(int size)
{
    int *p = (int *)alloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        p[i] = 2 * i + 1;
    }
    return p;
}

char *charArray(int size)
{
    char *p = (char *)alloc(size * sizeof(char));
    for (int i = 0; i < size; i++)
    {
        p[i] = 'X';
    }
    return p;
}

float *floatArray(int size)
{
    float *p = (float *)alloc(size * sizeof(float));
    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1;
    }
    return p;
}
