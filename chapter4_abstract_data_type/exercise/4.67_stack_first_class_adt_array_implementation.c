#include<stdlib.h>
#include"stack.h"

struct stack{
	item_t *array;
	int top;
	int Nmax;
};

stack_t stackInit(int Nmax)
{
	stack_t s=malloc(sizeof(*s));
	s->array = malloc(Nmax*sizeof(item_t));
	s->top = 0;
	s->Nmax = Nmax;
	
	return(s);
}

int stackEmpty(stack_t s)
{
	return(s->top == 0);
}

void stackPush(stack_t s,item_t item)
{
	(s->array)[(s->top) ++]=item;
}

item_t stackPop(stack_t s)
{
	return((s->array)[-- (s->top)]);
}
