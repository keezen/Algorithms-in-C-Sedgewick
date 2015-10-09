#ifndef MATRIX_H
#define MATRIX_H

#include"item.h"

typedef struct matrix* matr_t;
matr_t matrixInit(int M,int N,int index_r,int index_c,item_t item);
matr_t matrixAdd(matr_t,matr_t);
matr_t matrixNumMult(matr_t,int);
matr_t matrixMult(matr_t,matr_t);
void matrixPrint(matr_t);
void matrixDest(matr_t);

#endif
