#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"

link_t generate_node(int i)
{
	link_t x;
	x=malloc(sizeof(*x));
	x->item=i;
	x->next=x;
}

link_t free_nodes(link_t head)
{
	link_t x;
	int i;

	x=head;
	while(Next(x)!=NULL){
		for(i=1;i<5 && Next(x)!=NULL;x=Next(x),i++);

		if(Next(x)!=NULL)
			free(deleteNext(x));
	}

	return(head);	
}

void print_list(const link_t head)
{
	link_t x;
	printf("the list:");
	for(x=Next(head);x!=NULL;x=Next(x))
		printf("%2d ",Item(x));
	putchar('\n');
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]),i;
	link_t head,x,temp,t,u;

	head=generate_node(0);
	head->next=NULL;

	srand((unsigned)time(NULL));

	for(x=head,i=1;i<=N;i++){
		temp=generate_node(rand()%100);
		insertNext(x,temp);
		x=temp;
	}
	print_list(head);

	head=free_nodes(head);
	print_list(head);	

	return(0);
}
