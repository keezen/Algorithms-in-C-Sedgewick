#include<stdlib.h>
#include<stdio.h>
#include"stack.h"

typedef struct node* link_t;
struct node{
	item_t item;
	link_t prev;
	link_t next;
};

static link_t head,tail;
static link_t *array;

void stackInit(int M)
{
	int i;

	head=tail=NULL;
	array=malloc(M*sizeof(link_t));
	for(i=0;i<M;i++)
		array[i]=NULL;
}

int stackEmpty(void)
{
	return(head==NULL);
}

link_t deleteNode(link_t x)
{
	if(x==head){
		head=x->next;
		head->prev=NULL;
		return(x);
	}

	if(x==tail){
		tail=x->prev;
		tail->next=NULL;
		return(x);
	}

	x->prev->next=x->next;
	x->next->prev=x->prev;
	
	return(x);
}

void forgetOld(link_t x)
{
	free(deleteNode(x));
}

void stackPush(item_t item)
{
	link_t x=malloc(sizeof(*x));
	x->item=item;
	x->prev=x->next=NULL;
	
	if(array[item]!=NULL){
		forgetOld(array[item]);
		array[item]=NULL;
	}	

	array[item]=x;

	if(head==NULL){
		head=tail=x;
		return;
	}

	x->next=head;
	head->prev=x;
	x->prev=NULL;
	head=x;
}

item_t stackPop(void)
{
	item_t x=head->item;
	link_t t=head->next;
	
	array[x]=NULL;	

	if(t==NULL){
		free(head);
		head=NULL;
		return(x);
	}

	free(head);
	t->prev=NULL;
	head=t;	
	return(x);
}

void stackDump(void)
{
	link_t x;
	for(x=tail;x!=NULL;x=x->prev)
		printf("%d ",x->item);
}
