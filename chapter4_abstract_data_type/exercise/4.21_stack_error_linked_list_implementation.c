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

int stackEmpty(void)
{
	return(head==NULL);
}

void stackError(void)
{
	puts("Illegal Operation.");
}

void stackPush(item_t x)
{
	link_t t=malloc(sizeof(*t));
	
	if(t==NULL)
		stackError();
	else{
		t->item=x;
		t->next=head;
		head=t;
	}
}

item_t stackPop(void)
{
	if(stackEmpty())
		stackError();
	else{
		item_t x=head->item;
		link_t t=head->next;
		free(head);
		head=t;
		return(x);
	}
}
