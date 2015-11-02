/*
** This program implements the LSD radix sort using linked list.
*/
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
link_t lsd_radixsort(link_t head);

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

	head=lsd_radixsort(head);
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
** The LSD radix sort using linked list is implemented by the same idea of that using array:
** move from right to left, sort the file by a stable method according to every byte, when 
** the all bytes have been examined, the file is sorted. The difference is the key-indexed
** counting method. In this linked list implementation, we split the files into R parts (
** including empty bins), according to their current byte, just as the key-indexed counting.
** Then we merge these parts in order into one, so that the stable sorting of the current byte
** is accomplished.
*/
link_t lsd_radixsort(link_t head)
{
	link_t heads[R];
	link_t tails[R];
	link_t t,previous;
	int i,w,index;

	if(head==NULL || head->next==NULL){
		return(head);
	}

	for(w=bytesword-1;w>=0;w--){
		for(i=0;i<R;i++){
			heads[i]=tails[i]=NULL;
		}

		
		/*
		** Split the files into R parts.
		*/
		while(head!=NULL){
			t=head;
			head=head->next;
			t->next=NULL;
	
			index=digit(t->item,w);
			if(tails[index]==NULL){
				heads[index]=tails[index]=t;
			}else{
				tails[index]->next=t;
				tails[index]=t;
			}
		}


		/*
		** Connect these parts in order, tail to head.
		*/
		for(i=0;i<R && heads[i]==NULL;i++)
			;
		head=heads[i];
		previous=tails[i];

		for(i++;i<R;i++){
			if(heads[i]!=NULL){
				previous->next=heads[i];
				previous=tails[i];
			}		
		}			
	}

	return(head);
}
