#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"
#include"item.h"

link_t merge_list(link_t heada,link_t headb);
link_t mergesort_list(link_t head,int length);

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
** The implementation of top-down list mergesort that carries the
** list length as a parameter to the recursive procedure and uses
** it to split the lists.
*/
link_t mergesort_list(link_t head,int length)
{
	link_t heada,headb;
	link_t t;
	int middle=(length+1)/2;
	int i;

	if(head==NULL || head->next==NULL){
		return(head);
	}

	heada=head;
	headb=head;
	for(i=1;i<middle;i++){
		headb=headb->next;
	}

	t=headb;
	headb=t->next;
	t->next=NULL;

	heada=mergesort_list(heada,middle);
	headb=mergesort_list(headb,length-middle);
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

	head=mergesort_list(head,N);
	print_list(head);

	return(0);
}
