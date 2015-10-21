#ifndef PQUEUE_H
#define PQUEUE_H

#include"item.h"

void pqueue_init(int Nmax);
int pqueue_empty(void);
void pqueue_insert(item_t item);
item_t pqueue_del_max(void);

#endif
