#include<stdlib.h>
#include"item.h"
#include"stack.h"

typedef struct stackNode* link_t;
struct stackNode{
	item_t item;
	link_t next;
};

static link_t first,last;

void stackInit(int Nmax)
{
	first=last=NULL;
}

int stackEmpty(void)
{
	return(first==NULL);
}

void stackError(void)
{
	puts("Illegal Operation.");
}

void stackPush(item_t x)
{
	link_t t=malloc(sizeof(*t));
	t->item=x;
	t->next=NULL;
	if(last!=NULL)
		last->next=t;
	else
		first=last=t;

	last=t;
}

item_t stackPop(void)
{
	if(stackEmpty())
		stackError();
	else{
		item_t x=last->item;
		link_t t;
		
		if(first!=last){
			for(t=first;t->next!=last;t=t->next);	
			t->next=NULL;
		}else
			first=t=NULL;
	
		free(last);
		last=t;
	
		return(x);
	}
}
