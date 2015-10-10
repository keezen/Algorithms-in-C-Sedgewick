#include<stdlib.h>
#include"dirlist.h"

link_t allocNode(item_t i)
{
	link_t x;
	x=malloc(sizeof(*x));
	x->next=x;
	x->item=i;
	
	return(x);
}

void freeNode(link_t x)
{
	free(x);
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

item_t Item(link_t x)
{
	return(x->item);
}
