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

static int item_existed(item_t item)
{
	int i;

	for(i=0;i<top && array[i]!=item;i++)
		;
	return(i!=top);
}

int find_item(item_t item)
{
	int i;
	for(i=0;array[i]!=item;i++)
		;
	return(i);
}

void oldForget(int old)
{
	int i;
	for(i=old;i<=top-2;i++)
		array[i]=array[i+1];
	top--;
}

void stackPush(item_t item)
{
	if(item_existed(item))
		oldForget(find_item(item));

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
		printf("%c ",array[i]);
}
