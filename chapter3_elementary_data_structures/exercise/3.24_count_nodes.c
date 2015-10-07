#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node* link_t;

struct node{
	int item;
	link_t next;
};

int main(void)
{
	int i,N,count_node;
	link_t x,temp,start_node;

	srand((unsigned)time(NULL));
	N=rand()%10+10;
	printf("N:%d\n",N);

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

	count_node=0;
	start_node=x;
	
	for(count_node++,x=x->next;x!=start_node;count_node++,x=x->next);

	printf("the number of nodes:%d\n",count_node);

	return(0);
}
