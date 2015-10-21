/*
** The lazy implementation of priority queue where the list is ordered
** only when a delete the maximum or a find the maximum operation is
** performed. Insertions since the previous sort are kept on a seperate
** list head_insert. The list head_insert is sorted and merged with the
** list head_sort when necessary, and the result is kept in the list
** head_sort. 
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

static pqueue_link_t head_sort=NULL;
static pqueue_link_t head_insert=NULL;
/*
** The integer is_sorted is a flag to show whether two lists are merged and
** sorted right now. If is_sorted==0, it means that some items are held in
** the list head_insert. If is_sorted==1, it shows that all elements are sorted
** in the list head_sort.
*/
static int is_sorted=0;

static pqueue_link_t merge_list_reverse(pqueue_link_t heada,pqueue_link_t headb);
static pqueue_link_t mergesort_list_reverse(pqueue_link_t head);

void pqueue_init(int N)
{
	head_sort=NULL;
	head_insert=NULL;
	is_sorted=0;
}

int pqueue_empty(void)
{
	return(head_sort==NULL && head_insert==NULL);
}

void pqueue_insert(item_t item)
{
	pqueue_link_t new;

	new=malloc(sizeof(*new));
	new->item=item;
	new->next=NULL;

	if(head_insert==NULL){
		head_insert=new;
	}else{
		new->next=head_insert;
		head_insert=new;
	}

	if(is_sorted==1){
		is_sorted=0;
	}
}

item_t pqueue_del_max(void)
{
	item_t item;
	pqueue_link_t t;

	assert(!pqueue_empty());

	if(is_sorted==0){
		head_insert=mergesort_list_reverse(head_insert);
		head_sort=merge_list_reverse(head_sort,head_insert);
		head_insert=NULL;

		is_sorted=1;
	}

	t=head_sort;
	item=head_sort->item;
	head_sort=head_sort->next;
	free(t);

	return(item);		
}

static pqueue_link_t mergesort_list_reverse(pqueue_link_t head)
{
	pqueue_link_t heada,headb;
	pqueue_link_t x,t;

	if(head==NULL || head->next==NULL){
		return(head);
	}

	heada=head;
	headb=head;
	x=head->next;
	while(x!=NULL && x->next!=NULL){
		headb=headb->next;
		x=x->next->next;
	}

	t=headb;
	headb=t->next;
	t->next=NULL;

	heada=mergesort_list_reverse(heada);
	headb=mergesort_list_reverse(headb);
	head=merge_list_reverse(heada,headb);

	return(head);
}

static pqueue_link_t merge_list_reverse(pqueue_link_t heada,pqueue_link_t headb)
{
	pqueue_link_t c,t;
	pqueue_link_t head=malloc(sizeof(*head));
	
	c=head;
	c->next=NULL;
	while(heada!=NULL && headb!=NULL){
		if(compare_item(heada->item,headb->item)>=0){
			t=heada;
			heada=t->next;
			t->next=NULL;

			c->next=t;
			c=t;
		}else{
			t=headb;
			headb=t->next;
			t->next=NULL;

			c->next=t;
			c=t;
		}
	}

	if(heada==NULL){
		c->next=headb;
	}else{
		c->next=heada;
	}

	t=head;
	head=head->next;
	free(t);

	return(head);
}
