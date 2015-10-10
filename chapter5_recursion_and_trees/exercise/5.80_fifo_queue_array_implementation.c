#include<stdlib.h>
#include<stdio.h>
#include"queue.h"
#include"tree.h"

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

void queuePut(item_t item)
{
	array[tail++]=item;
	tail%=N;
}

item_t queueGet(void)
{
	item_t t=array[head++];
	head%=N;
	return(t);
}

void queueItemPrint(void)
{
	int i,end=tail-1;

	if(queueEmpty())
		return;	
	
	end=(end<0)?(end+=N):end;
	
	i=head;
	while(i!=end){
		printf("%c ",Cont(array[i]));
		i++;
		i%=N;
	}
	printf("%c ",Cont(array[i]));	
}
