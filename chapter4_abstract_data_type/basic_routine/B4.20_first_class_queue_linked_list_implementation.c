#include<stdlib.h>
#include<stdio.h>
#include"queue.h"

typedef struct node* link_t;
struct node{
	item_t item;
	link_t next;
};
struct queue{
	link_t head;
	link_t tail;
};

queue_t queueInit(int N)
{	
	queue_t q=malloc(sizeof(*q));
	q->head=q->tail=NULL;
	return(q);
}

int queueEmpty(queue_t q)
{
	return(q->head==NULL);
}

void queuePut(queue_t q,item_t item)
{
	link_t x=malloc(sizeof(*x));
	x->item=item;

	if(q->tail==NULL){
		q->head=q->tail=x;
		return;
	}

	x->next=q->tail->next;
	q->tail->next=x;
	q->tail=x;
}

item_t queueGet(queue_t q)
{
	item_t x=q->head->item;
	link_t t=q->head->next;
	free(q->head);
	q->head=t;
	return(x);
}

void queueDump(queue_t q)
{
	link_t x;

	for(x=q->head;x!=NULL;x=x->next)
		printf("%d ",x->item);
}
