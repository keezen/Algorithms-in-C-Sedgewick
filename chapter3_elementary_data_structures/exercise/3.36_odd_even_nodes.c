#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"

link_t put_even_after_odd(const link_t head)
{
	link_t x,t,even,odd;

	for(odd=Next(head),x=Next(Next(head));x!=NULL && Next(x)!=NULL;x=Next(x)){
		t=deleteNext(x);
		insertNext(odd,t);
		odd=t;
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

	put_even_after_odd(head);	
	print_list(head);

	return(0);
}
