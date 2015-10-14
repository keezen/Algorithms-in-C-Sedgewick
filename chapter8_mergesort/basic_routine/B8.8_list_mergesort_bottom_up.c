#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"queue.h"
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
** This function uses a queue ADT to implement a bottom-up mergesort.
** Queue elements are ordered linked lists. After initializing the 
** queue with lists of length 1, the function simply removes two lists
** from the queue, merges them, and puts the result back on the queue,
** continuing until there is only one list. This corresponds to a sequence
** of passes through all the elements, doubling the length of the ordered
** lists on each pass, as in bottom-up mergesort.
*/
link_t mergesort_list(link_t head)
{
	link_t x,y,t;

	if(head==NULL || head->next==NULL){
		return(head);
	}

	queue_init(0);

	while(head!=NULL){
		t=head;
		head=head->next;
		t->next=NULL;
		
		queue_put(t);
	}

	x=queue_get();
	while(!queue_empty()){
		y=queue_get();
		t=merge_list(x,y);
		queue_put(t);

		x=queue_get();
	}

	return(x);
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
