#include<stdlib.h>
#include"queue.h"

typedef struct node* link_t;
struct node{
	item_t item;
	link_t next;
};

static link_t head,tail;

void queueInit(int Nmax)
{
	head=tail=NULL;
}

int queueEmpty(void)
{
	return(head==NULL);
}

void queuePut(item_t item)
{
	link_t x=malloc(sizeof(*x));
	x->item=item;
	x->next=x;

	if(head==NULL)
		head=tail=x;
	
	tail->next=x;
	x->next=head;
	tail=x;
}

item_t queueGet(void)
{
	item_t x=head->item;
	link_t t=head->next;

	if(head->next==head){
		free(head);
		head=tail=NULL;
		return(x);
	}
		
	tail->next=t;
	free(head);
	head=t;

	return(x);
}
