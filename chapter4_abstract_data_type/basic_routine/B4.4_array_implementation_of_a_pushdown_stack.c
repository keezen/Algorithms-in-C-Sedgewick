#include<stdlib.h>
#include"item.h"
#include"stack.h"

static int top;
static item_t *array;

void stackInit(int Nmax)
{
	array=malloc(Nmax*sizeof(item_t));
	top=0;
}

int stackEmpty(void)
{
	return(top==0);
}

void stackPush(item_t item)
{
	array[top++]=item;
}

item_t stackPop(void)
{
	return(array[--top]);
}
