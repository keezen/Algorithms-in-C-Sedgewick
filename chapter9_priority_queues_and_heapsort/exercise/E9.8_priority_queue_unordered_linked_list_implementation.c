/*
** The implementation for the basic priority queue interface that use
** an unordered linked list for the underlying data structure. The 
** pqueue_del_max operations uses linear time.
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
	pqueue_link_t new=malloc(sizeof(*new));

	new->item=item;
	new->next=head;
	head=new;
}

item_t pqueue_del_max(void)
{
	pqueue_link_t x,max;
	pqueue_link_t *pmax;
	item_t t;

	assert(!pqueue_empty());

	/*
	** max is the pointer to the current node, while *pmax is the memory
	** that saves the list pointer to the current node.
	*/
	pmax=&head;
	max=head;
	for(x=head;x->next!=NULL;x=x->next){
		if(compare_item(x->next->item,max->item)>0){
			pmax=&x->next;
			max=x->next;
		}
	}
	
	*pmax=max->next;
	t=max->item;
	free(max);

	return(t);
}
