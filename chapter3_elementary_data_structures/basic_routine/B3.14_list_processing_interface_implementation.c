#include<stdlib.h>
#include"list.h"

link_t freelist;

void initNodes(int N)
{
	int i;
	freelist=malloc((N+1)*sizeof(*freelist));
	for(i=0;i<N;i++)
		freelist[i].next=&freelist[i+1];
	freelist[N].next=NULL;
}

link_t newNode(int i)
{
	link_t x=deleteNext(freelist);
	x->next=x;
	x->item=i;
	
	return(x);
}

void freeNode(link_t x)
{
	insertNext(freelist,x);
}

void insertNext(link_t x,link_t t)
{
	t->next=x->next;
	x->next=t;
}

link_t deleteNext(link_t x)
{
	link_t t=x->next;
	x->next=t->next;
	
	return(t);
}

link_t Next(link_t x)
{
	return(x->next);
}

int Item(link_t x)
{
	return(x->item);
}
