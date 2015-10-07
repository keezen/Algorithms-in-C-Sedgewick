#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"

link_t reverse_list(link_t head)
{
	link_t r,y,t;

	r=NULL;
	y=Next(head);
	while(y!=NULL){
		t=Next(y);
		y->next=r;
		r=y;
		y=t;
	}
	head->next=r;

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

	head=reverse_list(head);			
	print_list(head);

	return(0);
}
