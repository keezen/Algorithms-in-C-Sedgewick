#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 100

typedef struct node* link_t;

struct node{
	int item;
	link_t next;
};

int main(void)
{
	int i,M,count_node;
	link_t x,temp,start_node,end_node;

	srand((unsigned)time(NULL));
	M=rand()%N;
	printf("M:%d\n",M);

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
	start_node=x;

	for(i=1;i<=M;x=x->next,i++);
	end_node=x;
	
	for(count_node=1,x=start_node;x!=end_node;count_node++,x=x->next);

	printf("the number of nodes between start node and end node:%d\n",count_node);

	return(0);
}
