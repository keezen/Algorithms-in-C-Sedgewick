#include<stdlib.h>
#include"dblist.h"

link_t freelist;

void initNodes(int N)
{
	int i;
	freelist=malloc((N+2)*sizeof(*freelist));
	for(i=1;i<=N;i++){
		freelist[i].next=&freelist[i+1];
		freelist[i].prev=&freelist[i-1];
	}
	freelist[0].next=&freelist[1];
	freelist[0].prev=&freelist[0];
	freelist[N+1].next=&freelist[N+1];
	freelist[N+1].prev=&freelist[N];
}

link_t newNode(int i)
{
	link_t x=deleteNode(Next(freelist));
	x->next=x;
	x->prev=x;
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
	x->next->prev=t;

	t->prev=x;
	x->next=t;
}

link_t deleteNode(link_t x)
{
	x->prev->next=x->next;
	x->next->prev=x->prev;
	
	return(x);
}

link_t Next(link_t x)
{
	return(x->next);
}

link_t Prev(link_t x)
{
	return(x->prev);
}

int Item(link_t x)
{
	return(x->item);
}
