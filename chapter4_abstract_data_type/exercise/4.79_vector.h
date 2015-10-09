#ifndef VECTOR_H
#define VECTOR_H

#include"item.h"

typedef struct vector* vector_t;
vector_t vectorInit(int N,int index,item_t item);
vector_t vectorAdd(vector_t,vector_t);
item_t vectorMult(vector_t,vector_t);
void vectorPrint(vector_t);

#endif
