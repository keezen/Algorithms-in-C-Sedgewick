#include<stdlib.h>
#include"item2.h"
#include"stack2.h"

typedef struct stackNode* link_t;
struct stackNode{
	item2_t item;
	link_t next;
};

static link_t head;

void stackInit2(int Nmax)
{
	head=NULL;
}

int stackEmpty2()
{
	return(head==NULL);
}

void stackPush2(item2_t x)
{
	link_t t=malloc(sizeof(*t));
	t->item=x;
	t->next=head;
	head=t;
}

item2_t stackPop2()
{
	item2_t x=head->item;
	link_t t=head->next;
	free(head);
	head=t;
	return(x);
}
