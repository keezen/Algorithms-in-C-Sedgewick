/*
** The implementation for the basic priority queue interface that use
** an ordered linked list for the underlying data structure. The 
** pqueue_insert operations uses linear time in the worst case.
*/
#include<stdlib.h>
#include<assert.h>
#include"item.h"
#include"pqueue.h"

typedef struct PQUEUE_NODE* pqueue_link_t;
struct PQUEUE_NODE{
	item_t item;
	pqueue_link_t next;
};

static pqueue_link_t head=NULL;

void pqueue_init(int N)
{
	head=NULL;
}

int pqueue_empty(void)
{
	return(head==NULL);
}

void pqueue_insert(item_t item)
{
	pqueue_link_t current,previous;
	pqueue_link_t new;

	previous=NULL;
	for(current=head;current!=NULL;current=current->next){
		if(compare_item(current->item,item)<=0){
			break;
		}
	
		previous=current;
	}

	new=malloc(sizeof(*new));
	new->item=item;
	new->next=current;

	if(previous==NULL){
		head=new;
		return;
	}

	previous->next=new;
}

item_t pqueue_del_max(void)
{
	item_t max_item=head->item;
	pqueue_link_t t=head;

	assert(!pqueue_empty());

	head=head->next;
	free(t);

	return(max_item);
}
