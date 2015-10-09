#ifndef QUEUE_H
#define	QUEUE_H

#include"item.h"

typedef struct queue* queue_t;
queue_t queueInit(int Nmax);
int queueEmpty(queue_t);
void queuePut(queue_t,item_t);
item_t queueGet(queue_t);
void queueDump(queue_t);

#endif
