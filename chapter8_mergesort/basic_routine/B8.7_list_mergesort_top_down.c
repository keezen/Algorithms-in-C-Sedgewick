#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"
#include"item.h"

link_t merge_list(link_t heada,link_t headb);
link_t mergesort_list(link_t head);

link_t merge_list(link_t heada,link_t headb)
{
	link_t c,t;
	link_t head=malloc(sizeof(*head));
	
	c=head;
	c->next=NULL;
	while(heada!=NULL && headb!=NULL){
		if(compare_item(heada->item,headb->item)<=0){
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

/*
** This function sorts the list pointed to by head, which splits
** the head list into two halves pointed by heada and headb. Sort
** the two halves recursively, and then using merge_list to produce
** the final result.
*/
link_t mergesort_list(link_t head)
{
	link_t heada,headb;
	link_t x,t;

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

	heada=mergesort_list(heada);
	headb=mergesort_list(headb);
	head=merge_list(heada,headb);

	return(head);
}

int main(int argc,char *argv[])
{
	link_t head,t;
	int N=atoi(argv[1]);
	int i;

	srand((unsigned)time(NULL));

	head=new_node(rand()%N);
	for(i=1;i<=N-1;i++){
		t=new_node(rand()%N);
		insert_next(head,t);
	}
	print_list(head);

	head=mergesort_list(head);
	print_list(head);

	return(0);
}
