#include<stdio.h>
#include<stdlib.h>

typedef struct node* link_t;

struct node{
	int item;
	link_t next;
};

link_t reverse_list(link_t x)
{
	link_t r=NULL,y=x,t;

	while(y!=NULL){
		t=y->next;
		y->next=r;
		r=y;
		y=t;
	}

	return(r);
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int i;
	link_t x,temp,first;

	first=x=malloc(sizeof(struct node));
	x->item=1;
	x->next=NULL;

	for(i=2;i<=N;i++){
		temp=x;
		x=malloc(sizeof(struct node));
		x->item=i;

		x->next=temp->next;
		temp->next=x;
	}

	temp=reverse_list(first);

	printf("nodes:");
	for(x=temp;x->next!=NULL;x=x->next)
		printf("%d ",x->item);
	printf("%d ",x->item);
	putchar('\n');

	return(0);
}
