/*
** This is the unordered doubly-linked-list implementation of priority
** queue. The implementation of the initialize, test if empty, insert,
** delete the maximum, change priority, delete, and join operations
** routines from the interface uses only elementary operations to
** maintain an unordered list, with head and tail nodes.
*/
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"pqueue_full.h"
#include"item.h"

struct PQUEUE_NODE{
	item_t item;
	pqueue_link_t prev;
	pqueue_link_t next;
};

struct PQUEUE{
	pqueue_link_t head;
	pqueue_link_t tail;
};

pqueue_t pqueue_init(int Nmax)
{
	pqueue_t pq=malloc(sizeof(*pq));
	pqueue_link_t h,t;

	h=malloc(sizeof(*h));
	t=malloc(sizeof(*t));
	h->next=t;
	t->prev=h;
	h->prev=NULL;
	t->next=NULL;

	pq->head=h;
	pq->tail=t;

	return(pq);
}

int pqueue_empty(pqueue_t pq)
{
	return(pq->head->next==pq->tail);
}

pqueue_link_t pqueue_insert(pqueue_t pq,item_t item)
{
	pqueue_link_t new;

	new=malloc(sizeof(*new));
	copy_item(&(new->item),&item);
	new->next=pq->head->next;
	new->next->prev=new;
	new->prev=pq->head;
	pq->head->next=new;

	return(new);
}

item_t pqueue_del_max(pqueue_t pq)
{
	pqueue_link_t x,max;
	item_t max_item;
	
	assert(!pqueue_empty(pq));

	max=pq->head->next;
	for(x=pq->head->next;x!=pq->tail;x=x->next){
		if(compare_item(x->item,max->item)>0){
			max=x;
		}
	}

	copy_item(&max_item,&(max->item));
	max->next->prev=max->prev;
	max->prev->next=max->next;
	free(max);

	return(max_item);
}

void pqueue_change(pqueue_t pq,pqueue_link_t node,item_t new_item)
{
	copy_item(&(node->item),&new_item);
}

void pqueue_delete(pqueue_t pq,pqueue_link_t node)
{
	node->next->prev=node->prev;
	node->prev->next=node->next;
	
	free(node);
}

pqueue_t pqueue_join(pqueue_t pq1,pqueue_t pq2)
{
	pq1->tail->prev->next=pq2->head->next;
	pq2->head->next->prev=pq1->tail->prev;

	free(pq1->tail);
	free(pq2->head);

	pq1->tail=pq2->tail;

	return(pq1);
}

void pqueue_print(pqueue_t pq)
{
	pqueue_link_t x;

	for(x=pq->head->next;x!=pq->tail;x=x->next){
		print_item(x->item);
		putchar(' ');	
	}
	putchar('\n');
}
