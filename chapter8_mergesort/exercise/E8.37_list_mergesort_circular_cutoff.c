#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"olist.h"
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
** The bottom-up circular-list mergesort with a cutoff for small 
** subfiles of size M. Fist sort the subfile whose size is less
** than M with insertion sort. Put the ordered subfiles in the 
** circular list and merge them.
*/
link_t mergesort_list(link_t head)
{
	link_t new,t,x,a,b;
	link_t circle_h,circle_t;
	int i;

	if(head==NULL || head->next==NULL){
		return(head);
	}

	circle_h=circle_t=NULL;
	while(head!=NULL){
		/*
		** Take out M elements, sort them with insertion sort.
		*/
		t=head;
		for(x=head,i=1;i<M;i++){
			if(x->next==NULL)
				break;
			x=x->next;
		}
		head=x->next;
		x->next=NULL;
		t=insertion_sort_list(t);

		new=malloc(sizeof(*new));
		new->item=0;
		new->out=t;
		if(circle_t==NULL){
			circle_h=circle_t=new;
			new->next=circle_h;
		}else{
			circle_t->next=new;
			new->next=circle_h;
			circle_t=new;
		}
	}

	for(a=circle_h;(a->next)!=a;a=a->next){
		b=a->next;

		a->out=merge_list(a->out,b->out);
		a->next=b->next;
		free(b);
	}
	
	head=a->out;
	free(a);

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
//	print_list(head);
	printf("sorted time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

	return(0);
}
