#ifndef PQUEUE_H
#define PQUEUE_H

#include"item.h"

typedef struct PQUEUE_ITEM{
	item_t item;
	int block;
} pqueue_item_t;

void pqueue_init(int Nmax);
int pqueue_empty(void);
void pqueue_insert(pqueue_item_t x);
void pqueue_replace_min(pqueue_item_t x);
pqueue_item_t pqueue_del_min(void);
pqueue_item_t pqueue_min(void);

#endif
