#include<stdlib.h>
#include<stdio.h>
#include"stack.h"

static int *array,*test;
static int top;

void stackInit(int Nmax)
{
	int i;	

	array=malloc((Nmax+1)*sizeof(int));
	test=malloc(Nmax*sizeof(int));
	top=0;

	for(i=0;i<Nmax;i++)
		test[i]=0;
}

int stackEmpty(void)
{
	return(top==0);
}

void stackPush(int item)
{
	if(test[item]==1)
		return;

	array[top++]=item;
	test[item]=1;
}

int stackPop(void)
{
	int x=array[--top];

	test[x]=0;

	return(x);
}

void stackDump(void)
{
	int i;
	for(i=0;i<top;i++)
		printf("%d ",array[i]);
}
