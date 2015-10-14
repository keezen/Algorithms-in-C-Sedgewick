#include<stdlib.h>
#include<stdio.h>
#include"queue.h"

typedef struct QUEUE_NODE* queue_link_t ;
struct QUEUE_NODE{
	queue_item_t item;
	queue_link_t next;
};

static queue_link_t first,last;

void queue_init(int N)
{
	first=last=NULL;
}

int queue_empty(void)	
{
	return(first==NULL);
}

void queue_put(queue_item_t item)
{
	queue_link_t x=malloc(sizeof(*x));
	x->item=item;
	x->next=NULL;

	if(last==NULL){
		first=last=x;
		return;
	}

	x->next=last->next;
	last->next=x;
	last=x;
}

queue_item_t queue_get(void)
{
	queue_item_t x=first->item;
	queue_link_t t=first->next;

	free(first);
	first=t;
	if(first==NULL){
		last=NULL;
	}
	
	return(x);
}
