#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"

link_t exchange_nodes(link_t head,link_t t,link_t u)
{
	link_t x,before_t,before_u;

	for(x=head;x!=NULL;x=Next(x)){
		if(Next(x)==t)
			before_t=x;
		if(Next(x)==u)
			before_u=x;
	}		
	
	deleteNext(before_t);
	deleteNext(before_u);
	insertNext(before_t,u);
	insertNext(before_u,t);

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

	initNodes(N+1);
	head=newNode(0);
	head->next=NULL;

	srand((unsigned)time(NULL));

	for(x=head,i=1;i<=N;i++){
		temp=newNode(rand()%100);
		insertNext(x,temp);
		x=temp;
		if(i==2)
			t=x;
		if(i==5)
			u=x;
	}
	print_list(head);

	exchange_nodes(head,t,u);	
	print_list(head);

	return(0);
}
