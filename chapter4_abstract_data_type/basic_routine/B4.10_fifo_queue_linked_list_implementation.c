#include<stdlib.h>
#include"queue.h"
#include"item.h"

typedef struct node* link_t;
struct node{
	item_t item;
	link_t next;
};

static link_t first,last;

void queueInit(int N)
{
	first=last=NULL;
}

int queueEmpty(void)
{
	return(first==NULL);
}

void queuePut(item_t item)
{
	link_t x=malloc(sizeof(*x));
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

item_t queueGet(void)
{
	item_t x=first->item;
	link_t t=first->next;

	free(first);
	first=t;
	if(first==NULL){
		last=NULL;
	}

	return(x);
}
