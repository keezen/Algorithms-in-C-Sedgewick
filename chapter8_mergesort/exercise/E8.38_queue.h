#ifndef QUEUE_H
#define	QUEUE_H

#include"list.h"
typedef link_t queue_item_t;

void queue_init(int N);
int queue_empty(void);
void queue_put(queue_item_t x);
queue_item_t queue_get(void);

#endif
