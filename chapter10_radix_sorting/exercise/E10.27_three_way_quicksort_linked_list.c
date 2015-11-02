#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

typedef struct NODE* link_t;
struct NODE{
	item_t item;
	link_t next;
};

void print_list(link_t head);
link_t three_way_quicksort(link_t head);

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

	head=three_way_quicksort(head);
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

/*
** The three_way_quicksort function sorts the list head using the idea of three-way partitioning.
** First, we divide the list into three parts: list of elements less then the first element, list
** of elements equal to the first, and list of elements more. Then we call recursively the
** function to sort the less list and the more list. Finally we merge the three parts in order.
*/
link_t three_way_quicksort(link_t head)
{
	link_t equal_head,equal_tail;
	link_t less_head,less_tail;
	link_t more_head,more_tail;
	link_t t;
	item_t v;

	if(head==NULL || head->next==NULL){
		return(head);
	}

	/*
	** Divide the list into three parts.
	*/
	equal_head=equal_tail=head;
	head=head->next;
	equal_head->next=equal_tail->next=NULL;
	copy_item(&v,&equal_head->item);

	less_head=less_tail=NULL;
	more_head=more_tail=NULL;
	while(head!=NULL){
		t=head;
		head=head->next;
		t->next=NULL;

		if(compare_item(t->item,v)==0){
			equal_tail->next=t;
			equal_tail=t;
			continue;
		}

		if(compare_item(t->item,v)<0){
			if(less_tail==NULL){
				less_head=less_tail=t;
			}else{
				less_tail->next=t;
				less_tail=t;
			}
			continue;
		}

		if(compare_item(t->item,v)>0){
			if(more_tail==NULL){
				more_head=more_tail=t;
			}else{
				more_tail->next=t;
				more_tail=t;
			}
			continue;
		}
	}

	/*
	** Recursively sort the less list and the more list.
	*/
	if(less_head!=NULL){
		less_head=three_way_quicksort(less_head);
		for(less_tail=less_head;less_tail->next!=NULL;less_tail=less_tail->next)
			;	
	}
	if(more_head!=NULL){
		more_head=three_way_quicksort(more_head);
		for(more_tail=more_head;more_tail->next!=NULL;more_tail=more_tail->next)
			;	
	}


	/*
	** Merge three parts into one.
	*/
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
