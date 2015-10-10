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
