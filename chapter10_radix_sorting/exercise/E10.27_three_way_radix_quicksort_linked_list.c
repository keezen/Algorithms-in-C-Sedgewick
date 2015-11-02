#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

typedef struct NODE* link_t;
struct NODE{
	item_t item;
	link_t next;
};

void print_list(link_t head);
link_t three_way_radix_quicksort(link_t head);
link_t do_three_way_radix_quicksort(link_t head,int w);

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	link_t head,new;
	int i;

	srand((unsigned)time(NULL));

	head=NULL;
	for(i=0;i<N;i++){
		new=malloc(sizeof(*new));
		new->item=rand()%N;
		new->next=NULL;

		new->next=head;
		head=new;
	}
	print_list(head);

	head=three_way_radix_quicksort(head);
	print_list(head);		

	return(0);
}

void print_list(link_t head)
{
	link_t x;

	for(x=head;x!=NULL;x=x->next){
		print_item(x->item);
		putchar(' ');
	}
	putchar('\n');
}

link_t three_way_radix_quicksort(link_t head)
{
	return(do_three_way_radix_quicksort(head,0));
}

/*
** The implementation of three-way radix quicksort for linked list, whose idea
** is almost the same as three-way partitioning quicksort.
*/
link_t do_three_way_radix_quicksort(link_t head,int w)
{
	link_t equal_head,equal_tail;
	link_t less_head,less_tail;
	link_t more_head,more_tail;
	link_t t;
	int v;

	if(head==NULL || head->next==NULL || w>=bytesword){
		return(head);
	}

	equal_head=equal_tail=head;
	head=head->next;
	equal_head->next=equal_tail->next=NULL;
	v=digit(equal_head->item,w);

	less_head=less_tail=NULL;
	more_head=more_tail=NULL;
	while(head!=NULL){
		t=head;
		head=head->next;
		t->next=NULL;

		if(digit(t->item,w)==v){
			equal_tail->next=t;
			equal_tail=t;
			continue;
		}

		if(digit(t->item,w)<v){
			if(less_tail==NULL){
				less_head=less_tail=t;
			}else{
				less_tail->next=t;
				less_tail=t;
			}
			continue;
		}

		if(digit(t->item,w)>v){
			if(more_tail==NULL){
				more_head=more_tail=t;
			}else{
				more_tail->next=t;
				more_tail=t;
			}
			continue;
		}
	}


	equal_head=do_three_way_radix_quicksort(equal_head,w+1);
	for(equal_tail=equal_head;equal_tail->next!=NULL;equal_tail=equal_tail->next)
		;
	
	if(less_head!=NULL){
		less_head=do_three_way_radix_quicksort(less_head,w);
		for(less_tail=less_head;less_tail->next!=NULL;less_tail=less_tail->next)
			;	
	}

	if(more_head!=NULL){
		more_head=do_three_way_radix_quicksort(more_head,w);
		for(more_tail=more_head;more_tail->next!=NULL;more_tail=more_tail->next)
			;	
	}


	if(less_tail!=NULL){
		less_tail->next=equal_head;
		equal_tail->next=more_head;
		head=less_head;
	}else{
		equal_tail->next=more_head;
		head=equal_head;
	}

	return(head);
}
