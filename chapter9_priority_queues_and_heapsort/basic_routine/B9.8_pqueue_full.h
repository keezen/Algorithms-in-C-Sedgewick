/*
** This interface for a first-class priority queue ADT provides handles
** to items (which allow clients to delete items and to change priorities)
** and handles to priority queues (which allow clients to maintain multiple
** priority queues and to merge queues together).
*/
#ifndef PQUEUE_FULL_H
#define PQUEUE_FULL_H

#include"item.h"

typedef struct PQUEUE* pqueue_t;
typedef struct PQUEUE_NODE* pqueue_link_t;

pqueue_t pqueue_init(int Nmax);
int pqueue_empty(pqueue_t pq);
pqueue_link_t pqueue_insert(pqueue_t pq,item_t item);
item_t pqueue_del_max(pqueue_t pq);
void pqueue_change(pqueue_t pq,pqueue_link_t node,item_t new_item);
void pqueue_delete(pqueue_t pq,pqueue_link_t node);
pqueue_t pqueue_join(pqueue_t pq1,pqueue_t pq2);
void pqueue_print(pqueue_t pq);

#endif
