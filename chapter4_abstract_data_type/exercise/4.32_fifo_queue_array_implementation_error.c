#include<stdlib.h>
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

int queueFull(void)
{
	return((tail+1)%N==head);
}

static void queueError(void)
{
	puts("Error!!");
}

void queuePut(item_t item)
{
	if(queueFull()){
		queueError();
		return;		
	}

	array[tail++]=item;
	tail%=N;
}

item_t queueGet(void)
{
	if(queueEmpty()){
		queueError();
		return;
	}

	item_t t=array[head++];
	head%=N;
	return(t);
}
