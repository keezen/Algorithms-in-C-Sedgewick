/*
** The interface for priority queue data type, the pqueue_construct function
** will build an abstract priority queue from the given array.
*/
#ifndef PQUEUE_H
#define PQUEUE_H

#include"item.h"

void pqueue_init(int Nmax);
int pqueue_empty(void);
void pqueue_consruct(item_t *array,int left,int right);
void pqueue_insert(item_t item);
item_t pqueue_del_max(void);
void pqueue_print(void);

#endif
