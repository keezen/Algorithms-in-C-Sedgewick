#ifndef PQUEUE_H
#define PQUEUE_H

void pqueue_init(int Nmax);
int pqueue_empty(void);
void pqueue_consruct(int left,int right);
void pqueue_insert(int index);
int pqueue_del_max(void);
void pqueue_change(int index);
void pqueue_delete(int index);
void pqueue_print(void);

#endif
