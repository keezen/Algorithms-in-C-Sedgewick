/*
** Priority queue ADT interface for index items. Instead of building a
** data structure from the items themselves, this interface provides
** for building a priority queue using indices into a client array.
** The insert, delete the maximum, change priority, and delete routines
** all use a handle consisting of an array index. The client supplies
** a compare_index routine to compare two items.
*/
#ifndef PQUEUE_INDEX_H
#define PQUEUE_INDEX_H

void pqueue_init(int Nmax);
int pqueue_empty(void);
void pqueue_insert(int index);
int pqueue_del_max(void);
void pqueue_change(int index);
void pqueue_delete(int index);
void pqueue_print(void);

#endif
