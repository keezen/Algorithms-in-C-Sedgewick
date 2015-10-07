#include<stdio.h>
#include<stdlib.h>

typedef struct node* link_t;

struct node{
	int item;
	link_t next;
};

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]),M=atoi(argv[2]);
	int i;
	struct node *x,*temp;

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

	printf("quit order:");

	while(x->next!=x){
		for(i=1;i<M;i++)
			x=x->next;
		
		printf("%d ",x->next->item);
	
		x->next=x->next->next;
	}

	putchar('\n');
	printf("the target:%d\n",x->item);

	return(0);
}
