#include<stdlib.h>
#include"item.h"
#include"stack.h"

static int top;
static item_t *array;
static NMAX;

void stackInit(int Nmax)
{
	array=malloc(Nmax*sizeof(item_t));
	NMAX=Nmax;
	top=0;
}

int stackEmpty()
{
	return(top==0);
}

void stackError(void)
{
	puts("Illegal Operation.");
}

void stackPush(item_t item)
{
	if(top==NMAX)
		stackError();
	else
		array[top++]=item;
}

item_t stackPop()
{
	if(stackEmpty())
		stackError();
	else
		return(array[--top]);
}
