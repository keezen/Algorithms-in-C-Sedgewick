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
** The implementation of top-down list mergesort that works with
** lists that carry their length in dumb header nodes and uses
** the lengths to split the lists.
*/
link_t mergesort_list(link_t head)
{
	link_t heada,headb;
	link_t x,t;
	int length=head->item;
	int middle=(length+1)/2;
	int i;

	if(head->next==NULL || head->next->next==NULL){
		return(head);
	}

	heada=head;
	x=head->next;
	for(i=1;i<middle;i++){
		x=x->next;
	}

	t=x;
	x=t->next;
	t->next=NULL;

	headb=malloc(sizeof(*headb));
	headb->next=x;
	headb->item=length-middle;
	heada->item=middle;	


	heada=mergesort_list(heada);
	headb=mergesort_list(headb);
	head->next=merge_list(heada->next,headb->next);
	
	head->item=length;
	free(headb);

	return(head);
}

int main(int argc,char *argv[])
{
	link_t head,t;
	int N=atoi(argv[1]);
	int i;

	srand((unsigned)time(NULL));

	head=new_node(0);
	for(i=0;i<N;i++){
		t=new_node(rand()%N);
		insert_next(head,t);

		(head->item)++;
	}
	print_list(head->next);

	head=mergesort_list(head);
	print_list(head->next);

	return(0);
}
