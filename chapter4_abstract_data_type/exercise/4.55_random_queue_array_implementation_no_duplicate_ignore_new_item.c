#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"rq.h"

static item_t *array;
static int top;
static int N;

void RQinit(int Nmax)
{
	array=malloc((Nmax+1)*sizeof(item_t));
	top=0;
	N=Nmax;
	srand((unsigned)time(NULL));
}

int RQempty(void)
{
	return(top==0);
}

int RQfull(void)
{
	return(top==N-1);
}

static int item_existed(item_t item)
{
	int i;
	for(i=0;i<top;i++)
		if(array[i]==item)
			return(1);
	return(0);
}

void RQput(item_t item)
{
	if(item_existed(item))
		return;

	array[top++]=item;
}

static void swap_item(int i,int j)
{
	item_t t=array[i];
	array[i]=array[j];
	array[j]=t;
}

item_t RQget(void)
{
	int x=rand()%top;
	
	swap_item(x,top-1);

	return(array[--top]);
}

void RQdump(void)
{
	int i;
	for(i=0;i<top;i++)
		printf("%d ",array[i]);
}
