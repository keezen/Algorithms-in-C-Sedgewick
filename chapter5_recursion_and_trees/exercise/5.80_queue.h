#ifndef QUEUE_H
#define	QUEUE_H

#include"item.h"

void queueInit(int N);
int queueEmpty(void);
void queuePut(item_t);
item_t queueGet(void);
void queueItemPrint(void);

#endif
