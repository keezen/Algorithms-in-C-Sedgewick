#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"
#include"item.h"

#define M 9

link_t merge_list(link_t heada,link_t headb);
link_t mergesort_list(link_t head);
link_t insertion_sort_list(link_t head);

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
** Top-down mergesort with cutoff for small subfiles of size
** M.
*/
link_t mergesort_list(link_t head)
{
	link_t heada,headb;
	link_t x,t;
	int count;

	if(head==NULL || head->next==NULL){
		return(head);
	}

	/*
	** If the length of the list if less than(or equal to) the
	** cutoff M, then call the insertion_sort_list function to
	** sort it.
	*/
	for(count=0,x=head;x!=NULL;x=x->next){
		if(count==M)
			break;
		count++;
	}
	if(x==NULL){
		head=insertion_sort_list(head);
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

link_t insertion_sort_list(link_t head)
{
	link_t out,t;
	link_t current,*plink;

	out=NULL;
	while(head != NULL){
		t=head;
		head=head->next;
		t->next=NULL;

		plink=&out;
		current=out;
		while(current!=NULL && compare_item(current->item,t->item)<0){
			plink=&(current->next);
			current=current->next;
		}

		t->next=current;
		*plink=t;
	}

	return(out);
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
//	print_list(head);

	c1=clock();
	head=mergesort_list(head);
	c2=clock();
	printf("sorted time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);
//	print_list(head);

	return(0);
}
