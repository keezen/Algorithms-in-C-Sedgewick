/*
** The interface for first-class priority queue ADT, the pqueue_construct function
** will build an abstract priority queue from the given array.
*/
#ifndef PQUEUE_H
#define PQUEUE_H

#include"item.h"

typedef struct PQUEUE* pqueue_t;

pqueue_t pqueue_init(int Nmax);
int pqueue_empty(pqueue_t);
void pqueue_consruct(pqueue_t pq,item_t *array,int left,int right);
item_t pqueue_del_max(pqueue_t pq);
void pqueue_print(pqueue_t pq);

#endif
