#include<stdio.h>
#include"arrlist.h"

void print_list(link_t head)
{
	link_t x;
	printf("the list:");
	for(x=Next(head);x!=EOF;x=Next(x))
		printf("%2d ",Item(x));
	putchar('\n');
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]),M=atoi(argv[2]);
	int i;
	link_t x,t;

	initNodes(N);

	for(x=newNode(1),i=2;i<=N;i++){
		t=newNode(i);
		insertNext(x,t);
		x=t;
	}

	printf("quit order:");

	while(Next(x)!=x){
		for(i=1;i<M;x=Next(x),i++);
		
		printf("%d ",Item(Next(x)));
	
		freeNode(deleteNext(x));
	}

	putchar('\n');
	printf("the target:%d\n",Item(x));
	print_list(freelist);

	return(0);
}
