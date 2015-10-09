#include<stdlib.h>
#include<stdio.h>
#include"queue.h"

item_t *array;
int head,tail;
int N;

void queueInit(int Nmax)
{
	array=malloc((Nmax+1)*sizeof(item_t));
	head=tail=0;
	N=Nmax+1;
}

int queueEmpty(void)
{
	return(head==tail);
}

static int item_existed(item_t item)
{
	int i,end=tail-1;
	
	end=(end<0)?(end+=N):end;
	
	i=head;
	while(i!=end){
		if(array[i]==item)
			return(1);
		i++;
		i%=N;
	}

	return(array[i]==item);
}

void queuePut(item_t item)
{	
	if(item_existed(item))
		return;

	array[tail++]=item;
	tail%=N;
}

item_t queueGet(void)
{
	item_t t=array[head++];
	head%=N;
	return(t);
}

void queueDump(void)
{
	int i,end=tail-1;

	if(queueEmpty())
		return;	
	
	end=(end<0)?(end+=N):end;
	
	i=head;
	while(i!=end){
		printf("%c ",array[i]);
		i++;
		i%=N;
	}
	printf("%c ",array[i]);
}
