#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"list.h"
#include"item.h"

int count_ordered_subfile(link_t head);

/*
** This function counts the number of ordered subfiles in a random
** file pointed by head.
*/
int count_ordered_subfile(link_t head)
{
	link_t x;
	int count;

	x=head;
	count=0;
	while(x!=NULL){
		while(x->next!=NULL && compare_item(x->item,x->next->item)<=0){
			x=x->next;
		}
		
		count++;
		x=x->next;
	}

	return(count);
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
//	print_list(head);

	printf("number of ordered subfiles: %d\n",count_ordered_subfile(head));

	return(0);
}
