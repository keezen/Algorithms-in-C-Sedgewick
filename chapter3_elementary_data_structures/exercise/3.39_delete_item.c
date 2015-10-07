#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"

typedef int function_t(link_t);

int function(link_t x)
{
	return(Item(x)%2);
}

link_t delete_item(link_t head,function_t *function)
{
	link_t x=head;

	x=head;	
	while(Next(x)!=NULL)
		if(function(Next(x)))
			freeNode(deleteNext(x));
		else
			x=Next(x);

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

	delete_item(head,function);			
	print_list(head);

	return(0);
}
