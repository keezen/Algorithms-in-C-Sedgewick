#include<stdlib.h>
#include"deque.h"

static item_t *array;
static int head,tail,N;

void dequeInit(int Nmax)
{
	array=malloc((Nmax+1)*sizeof(item_t));
	head=0;tail=1;
	N=Nmax+1;
}

int dequeEmpty(void)
{
	return(head+1 == tail);
}

void dequePut_begin(item_t item)
{
	array[head--]=item;
	if(head<0)
		head+=N;
}

void dequePut_end(item_t item)
{
	array[tail++]=item;
	tail%=N;
}

item_t dequeGet_begin(void)
{
	head++;
	head%=N;

	return(array[head]);	
}

item_t dequeGet_end(void)
{
	tail--;
	if(tail<0)
		tail+=N;
	return(array[tail]);
}
