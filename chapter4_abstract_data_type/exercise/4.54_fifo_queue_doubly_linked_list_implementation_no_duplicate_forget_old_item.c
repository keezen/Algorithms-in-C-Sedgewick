#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

typedef struct node* link_t;
struct node{
	item_t item;
	link_t prev;
	link_t next;
};

static link_t head,tail;
static link_t *array;

void queueInit(int Nmax)
{
	int i;

	head=tail=NULL;
	array=malloc(Nmax*sizeof(link_t));
	for(i=0;i<Nmax;i++)
		array[i]=NULL;
}

int queueEmpty(void)
{
	return(head==NULL);
}

static link_t deleteNode(link_t x)
{
	if(x==tail){
		tail=x->prev;
		tail->next=NULL;
		return(x);
	}

	if(x==head){
		head=x->next;
		head->prev=NULL;
		return(x);
	}

	x->prev->next=x->next;
	x->next->prev=x->prev;
	return(x);
}

static void forgetOld(link_t x)
{
	free(deleteNode(x));
}

void queuePut(item_t item)
{
	link_t x=malloc(sizeof(*x));
	x->item=item;
	x->prev=x->next=NULL;

	if(array[item]!=NULL){
		forgetOld(array[item]);
		array[item]=NULL;
	}

	array[item]=x;

	if(tail==NULL){
		head=tail=x;
		return;
	}

	tail->next=x;
	x->prev=tail;
	x->next=NULL;
	tail=x;
}

item_t queueGet(void)
{
	item_t x=head->item;
	link_t t=head->next;

	array[x]=NULL;

	if(t==NULL){
		free(head);
		head=tail=NULL;
		return(x);
	}
		
	free(head);
	t->prev=NULL;
	head=t;

	return(x);
}

void queueDump(void)
{
	link_t x;

	for(x=head;x!=NULL;x=x->next)
		printf("%d ",x->item);
}
