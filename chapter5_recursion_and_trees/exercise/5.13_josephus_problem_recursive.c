#include<stdio.h>
#include"list.h"

int N,M;

link_t quit(link_t x)
{
	int i;

	if(x==Next(x))
		return(x);

	for(i=1;i<M;x=Next(x),i++)
		;

	printf("%d ",Item(Next(x)));

	freeNode(deleteNext(x));

	return(quit(x));	
}

int main(int argc,char *argv[])
{
	int i;
	link_t x,t;

	N=atoi(argv[1]),M=atoi(argv[2]);
	initNodes(N);

	for(x=newNode(1),i=2;i<=N;i++){
		t=newNode(i);
		insertNext(x,t);
		x=t;
	}

	printf("quit order:");

	t=quit(x);

	putchar('\n');
	printf("the target:%d\n",Item(t));

	return(0);
}
