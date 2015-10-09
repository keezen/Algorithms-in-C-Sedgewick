#include<stdlib.h>
#include"stack.h"

#define NIL -1

static int *array,head;

void stackInit(int Nmax)
{
	int i;
	array=malloc(Nmax*sizeof(int));
	for(i=0;i<Nmax;i++)
		array[i]=i;
	head=NIL;
}

int stackEmpty(void)
{
	return(head==NIL);
}

void stackError(void)
{
	puts("Illegal Operation.");
}

void stackPush(int x)
{
	array[x]=head;
	head=x;
}

int stackPop(void)
{
	if(stackEmpty())
		stackError();
	else{
		int x=head;
		head=array[head];
		return(x);
	}
}
