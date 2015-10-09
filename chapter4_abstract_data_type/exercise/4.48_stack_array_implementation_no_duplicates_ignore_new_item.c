#include<stdlib.h>
#include<stdio.h>
#include"stack.h"

static int top;
static item_t *array;

void stackInit(int Nmax)
{
	array=malloc((Nmax+1)*sizeof(item_t));
	top=0;
}

int stackEmpty(void)
{
	return(top==0);
}

static int existed(item_t item)
{
	int i;

	for(i=0;i<top && array[i]!=item;i++)
		;
	return(i!=top);
}

void stackPush(item_t item)
{
	if(existed(item))
		return;	

	array[top++]=item;
}

item_t stackPop(void)
{
	return(array[--top]);
}

void stackDump(void)
{
	int i;
	for(i=0;i<top;i++)
		printf("%d ",array[i]);
}
