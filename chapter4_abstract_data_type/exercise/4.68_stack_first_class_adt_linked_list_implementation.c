#include<stdlib.h>
#include"stack.h"

typedef struct stackNode* link_t;
struct stackNode{
	item_t item;
	link_t next;
};
struct stack{
	link_t head;
};

stack_t stackInit(int Nmax)
{
	stack_t s=malloc(sizeof(*s));
	s->head = NULL;
	return(s);
}

int stackEmpty(stack_t s)
{
	return(s->head == NULL);
}

void stackPush(stack_t s,item_t x)
{
	link_t t=malloc(sizeof(*t));
	t->item=x;
	t->next = s->head;
	s->head = t;
}

item_t stackPop(stack_t s)
{
	item_t x=s->head->item;
	link_t t=s->head->next;
	free(s->head);
	s->head=t;
	return(x);
}
