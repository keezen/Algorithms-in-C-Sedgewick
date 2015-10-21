/*
** This is the ordered doubly-linked-list implementation of priority
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
	pqueue_link_t new,x;

	new=malloc(sizeof(*new));
	copy_item(&(new->item),&item);
	new->prev=new->next=NULL;

	for(x=pq->head->next;x!=pq->tail;x=x->next){
		if(compare_item(x->item,item)<=0){
			break;
		}
	}
	new->next=x;
	new->prev=x->prev;
	new->next->prev=new;
	new->prev->next=new;

	return(new);
}

item_t pqueue_del_max(pqueue_t pq)
{	
	pqueue_link_t t;
	item_t max_item;

	assert(!pqueue_empty(pq));

	t=pq->head->next;
	copy_item(&max_item,&(t->item));

	t->next->prev=t->prev;
	t->prev->next=t->next;
	free(t);

	return(max_item);
}

// pqueue_change untested
void pqueue_change(pqueue_t pq,pqueue_link_t node,item_t new_item)
{
	pqueue_link_t n;	

	copy_item(&(node->item),&new_item);

	while(node->next != pq->tail){
		if(compare_item(node->item,node->next->item)>=0){
			break;
		}

		n=node->next;
		n->next->prev=n->prev;
		n->prev->next=n->next;

		n->next=node;
		n->prev=node->prev;
		n->next->prev=n;
		n->prev->next=n;
	}
}

void pqueue_delete(pqueue_t pq,pqueue_link_t node)
{
	node->next->prev=node->prev;
	node->prev->next=node->next;
	
	free(node);
}

pqueue_t pqueue_join(pqueue_t pq1,pqueue_t pq2)
{
	pqueue_t pq;
	pqueue_link_t t;

	pq=pqueue_init(0);
	
	while(!pqueue_empty(pq1) && !pqueue_empty(pq2)){
		if(compare_item(pq1->head->next->item,pq2->head->next->item)>=0){
			t=pq1->head->next;
		}else{
			t=pq2->head->next;
		}
		t->next->prev=t->prev;
		t->prev->next=t->next;
		
		t->next=pq->tail;
		t->prev=pq->tail->prev;
		t->next->prev=t;
		t->prev->next=t;
	}

	if(pqueue_empty(pq1)){
		pq2->tail->prev->next=pq->tail;
		pq2->head->next->prev=pq->tail->prev;
		pq->tail->prev->next=pq2->head->next;
		pq->tail->prev=pq2->tail->prev;
		
		pq2->head->next=pq2->tail;
		pq2->tail->prev=pq2->head;
	}else{
		pq1->tail->prev->next=pq->tail;
		pq1->head->next->prev=pq->tail->prev;
		pq->tail->prev->next=pq1->head->next;
		pq->tail->prev=pq1->tail->prev;
		
		pq1->head->next=pq1->tail;
		pq1->tail->prev=pq1->head;		
	}

	pqueue_destroy(pq1);
	pqueue_destroy(pq2);

	return(pq);
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

void pqueue_destroy(pqueue_t pq)
{
	pqueue_link_t t;

	while(!pqueue_empty(pq)){
		t=pq->head->next;
		t->next->prev=pq->head;
		pq->head->next=t->next;

		free(t);
	}

	free(pq->head);
	free(pq->tail);
	free(pq);
}
