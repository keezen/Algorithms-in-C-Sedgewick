#include<stdlib.h>
#include"item.h"
#include"stack.h"

typedef struct stackNode* link_t;
struct stackNode{
	item_t item;
	link_t next;
};

static link_t head;

void stackInit(int Nmax)
{
	head=NULL;
}

int stackEmpty()
{
	return(head==NULL);
}

int stackCount()
{
	link_t x;
	int count=0;
	for(x=head;x!=NULL;count++,x=x->next);
	return(count);
}

void stackPush(item_t x)
{
	link_t t=malloc(sizeof(*t));
	t->item=x;
	t->next=head;
	head=t;
}

item_t stackPop()
{
	item_t x=head->item;
	link_t t=head->next;
	free(head);
	head=t;
	return(x);
}
