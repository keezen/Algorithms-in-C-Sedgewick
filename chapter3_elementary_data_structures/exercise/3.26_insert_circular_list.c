#include<stdio.h>
#include<stdlib.h>

#define N 10

typedef struct node* link_t;

struct node{
	int item;
	link_t next;
};

int main(void)
{
	int i;
	link_t x,temp,circular_list1,circular_list2,start_node;

	x=malloc(sizeof(struct node));
	x->item=1;
	x->next=x;
	for(i=2;i<=N;i++){
		temp=x;
		x=malloc(sizeof(struct node));
		x->item=i;

		x->next=temp->next;
		temp->next=x;
	}
	circular_list1=x;

	x=malloc(sizeof(struct node));
	x->item=1+10;
	x->next=x;
	for(i=2;i<=N;i++){
		temp=x;
		x=malloc(sizeof(struct node));
		x->item=i+10;

		x->next=temp->next;
		temp->next=x;
	}
	circular_list2=x;

	temp=circular_list1->next;
	circular_list1->next=circular_list2->next;
	circular_list2->next=temp;

	printf("merged lists:");
	x=start_node=circular_list2->next;
	printf("%d ",x->item);
	for(x=x->next;x!=start_node;x=x->next)
		printf("%d ",x->item);
	putchar('\n');

	return(0);
}
