#ifndef MATRIX_H
#define MATRIX_H
#include <stdio.h>
#include <stdlib.h>
#include "stacklist.h"

#define Nmax 8
typedef int candy;
typedef candy Matrix[Nmax][Nmax];

void swap(candy *a, candy *b);

void printMatrix(Matrix m);

void Update(Stack *S, Matrix m, int *score);

void RemoveZero(Matrix m);

void GetChain(Stack *S, Matrix m);

#endif