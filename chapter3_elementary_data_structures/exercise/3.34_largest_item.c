#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"

link_t move_largest_item(const link_t head)
{
	link_t x=head,next_max,max,last_node;
	double max_value;
	
	for(max_value=Item(Next(x)),next_max=x;Next(x)!=NULL;x=Next(x))
		if(Item(Next(x)) > max_value)
			max_value=Item(Next(x)),next_max=x;
	last_node=x;

	if(Next(next_max)!=last_node){
		max=deleteNext(next_max);
		insertNext(last_node,max);
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
	link_t head,x,temp;

	initNodes(N+1);
	head=newNode(0);
	head->next=NULL;

	srand((unsigned)time(NULL));

	for(x=head,i=1;i<=N;i++){
		temp=newNode(rand()%100);
		insertNext(x,temp);
		x=temp;
	}

	print_list(head);

	move_largest_item(head);
	
	print_list(head);

	return(0);
}
