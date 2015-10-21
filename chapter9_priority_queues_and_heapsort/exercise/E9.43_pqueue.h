/*
** This interface defines operations for the simplest type of priority queue:
** initialize, test if empty, add a new item, remove the largest item. The 
** argument to pqueue_init specifies the maximum number of items expected in
** the queue.
*/
#ifndef PQUEUE_H
#define PQUEUE_H

#include"item.h"

typedef struct PQUEUE_NODE* pqueue_link_t;

void pqueue_init(int Nmax);
int pqueue_empty(void);
pqueue_link_t pqueue_insert(item_t item);
item_t pqueue_del_max(void);
void pqueue_change(pqueue_link_t node,item_t new_item);
void pqueue_delete(pqueue_link_t node);
void pqueue_print(void);

#endif
