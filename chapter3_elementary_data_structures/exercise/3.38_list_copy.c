#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"

link_t copy_list(const link_t head1)
{
	link_t head2,x,y,temp;

	head2=newNode(0);
	head2->next=NULL;

	for(y=head2,x=Next(head1);x!=NULL;x=Next(x)){
		temp=newNode(0);
		temp->item=Item(x);

		insertNext(y,temp);
		y=temp;
	}

	return(head2);
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
	link_t head1,head2,x,temp;

	initNodes(2*N+2);
	head1=newNode(0);
	head1->next=NULL;

	srand((unsigned)time(NULL));

	for(x=head1,i=1;i<=N;i++){
		temp=newNode(rand()%100);
		insertNext(x,temp);
		x=temp;
	}

	head2=copy_list(head1);
	print_list(head1);			
	print_list(head2);

	return(0);
}
