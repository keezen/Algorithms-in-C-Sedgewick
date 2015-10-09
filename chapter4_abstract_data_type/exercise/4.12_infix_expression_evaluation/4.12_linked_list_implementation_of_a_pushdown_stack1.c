#include<stdlib.h>
#include"item1.h"
#include"stack1.h"

typedef struct stackNode* link_t;
struct stackNode{
	item1_t item;
	link_t next;
};

static link_t head;

void stackInit1(int Nmax)
{
	head=NULL;
}

int stackEmpty1()
{
	return(head==NULL);
}

void stackPush1(item1_t x)
{
	link_t t=malloc(sizeof(*t));
	t->item=x;
	t->next=head;
	head=t;
}

item1_t stackPop1()
{
	item1_t x=head->item;
	link_t t=head->next;
	free(head);
	head=t;
	return(x);
}
