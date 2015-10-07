#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"dblist.h"

link_t exchange_node(link_t head,link_t tail,link_t t,link_t u)
{
	link_t x,before_t,before_u;

	for(x=head;Next(x)!=tail;x=Next(x)){
		if(Next(x)==t)
			before_t=x;
		if(Next(x)==u)
			before_u=x;
	}		
	
	deleteNode(t);
	deleteNode(u);
	insertNext(before_t,u);
	insertNext(before_u,t);

	return(head);
}

void print_list(link_t head,link_t tail)
{
	link_t x;
	printf("the list:");
	for(x=Next(head);x!=tail;x=Next(x))
		printf("%2d ",Item(x));
	putchar('\n');
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]),i;
	link_t head,tail,x,temp,t,u;

	initNodes(N+2);
	srand((unsigned)time(NULL));

	head=newNode(0);
	tail=newNode(0);
	head->prev=head;
	tail->next=tail;
	head->next=tail;
	tail->prev=head;

	for(x=head,i=1;i<=N;i++){
		temp=newNode(rand()%100);
		insertNext(x,temp);
		x=temp;
		if(i==2)
			t=x;
		if(i==5)
			u=x;
	}
	print_list(head,tail);

	exchange_node(head,tail,t,u);	
	print_list(head,tail);

	return(0);
}
