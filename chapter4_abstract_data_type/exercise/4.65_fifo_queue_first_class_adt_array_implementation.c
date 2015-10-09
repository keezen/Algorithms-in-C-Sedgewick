#include<stdlib.h>
#include"queue.h"

struct queue{
	item_t *array;
	int head;
	int tail;
	int N;
};

queue_t queueInit(int Nmax)
{
	queue_t q=malloc(sizeof(*q));
	q->array = malloc((Nmax+1)*sizeof(item_t));
	q->head = q->tail = 0;
	q->N = Nmax+1;
	return(q);
}

int queueEmpty(queue_t q)
{
	return(q->head == q->tail);
}

void queuePut(queue_t q,item_t item)
{
	q->array[q->tail ++]=item;
	q->tail %= q->N;
}

item_t queueGet(queue_t q)
{
	item_t t = q->array[q->head ++];
	q->head %= q->N;
	return(t);
}
