#include<stdio.h>
#include<stdlib.h>
#include"arrlist.h"

link_t *array;
link_t freelist;

void initNodes(int N)
{
	int i;
	array=malloc((N+1)*sizeof(*array));
	for(i=0;i<N;i++)
		array[i]=i+1;
	array[N]=EOF;
	freelist=0;
}
link_t newNode(int i)
{
	link_t x;
	for(x=freelist;Next(x)!=i;x=Next(x));
	x=deleteNext(x);

	array[x]=x;
	
	return(x);
}

void freeNode(link_t x)
{
	insertNext(freelist,x);
}

void insertNext(link_t x,link_t t)
{
	array[t]=array[x];
	array[x]=t;
}

link_t deleteNext(link_t x)
{
	link_t t=array[x];
	array[x]=array[t];
	
	return(t);
}

link_t Next(link_t x)
{
	return(array[x]);
}

int Item(link_t x)
{
	return(x);
}
