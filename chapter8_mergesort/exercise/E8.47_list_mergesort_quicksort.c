#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"
#include"item.h"

link_t merge_list(link_t heada,link_t headb);
link_t mergesort_list(link_t head);
link_t quicksort_list(link_t head);

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

/*
** The implementation of top-down quicksort of linked list pointed to 
** by head. First take out the first node from the list head, save as
** current. Partition the whole file into two sublists, one sublist save
** the elements smaller than current->item, pointed to by head1. Another
** sublist head2, holds the elements larger than or equal to current->item.
** Call recursively quicksort_list to sort each of the two sublists. Then
** merge them with current to make the whole list sorted.
*/
link_t quicksort_list(link_t head)
{
	link_t head1,tail1;
	link_t head2,tail2;
	link_t current,t;

	if(head==NULL || head->next==NULL){
		return(head);
	}

	current=head;
	head=head->next;
	current->next=NULL;
	
	/*
	** Partition the list into two subfiles.
	*/
	head1=tail1=NULL;
	head2=tail2=NULL;
	while(head!=NULL){	
		t=head;
		head=head->next;
		t->next=NULL;

		if(compare_item(t->item,current->item)<0){			
			if(tail1==NULL){
				head1=tail1=t;
			}else{
				tail1->next=t;
				tail1=t;
			}
		}else{				
			if(tail2==NULL){
				head2=tail2=t;
			}else{
				tail2->next=t;
				tail2=t;
			}
		}
	}

	head1=quicksort_list(head1);
	head2=quicksort_list(head2);

	/*
	** This is a point you may ignore. After the recursive quicksort_list
	** call above, the pointer tail1 may not point to the tail of the sublist
	** head1. So you should traverse the sublist head1 to make sure tail1 points
	** to its tail.
	*/
	for(tail1=head1;tail1!=NULL && tail1->next!=NULL;tail1=tail1->next);
		;

	/*
	** Merge the two subfiles head1, head2 with current.
	*/
	if(tail1 != NULL){
		tail1->next=current;
		current->next=head2;
		head=head1;
	}else{
		current->next=head2;
		head=current;
	}

	return(head);
}

int main(int argc,char *argv[])
{
	link_t head,t;
	int N=atoi(argv[1]);
	int i;
	clock_t c1,c2;

	srand((unsigned)time(NULL));

	head=new_node(rand()%N);
	for(i=1;i<=N-1;i++){
		t=new_node(rand()%N);
		insert_next(head,t);
	}
	print_list(head);

	c1=clock();
	head=quicksort_list(head);
	c2=clock();
	print_list(head);
	printf("sorted time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

	return(0);
}
