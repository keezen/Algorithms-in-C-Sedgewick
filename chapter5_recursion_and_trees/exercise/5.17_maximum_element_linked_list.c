#include<stdio.h>
#include"dirlist.h"

#define N 10

item_t max(link_t head)
{
	item_t x,y;

	if(Next(head)==NULL)
		return(Item(head));

	x=Item(head);
	y=max(head->next);
	if(x>y)
		return(x);
	return(y);
}

int main(void)
{
	link_t head,x;
	int i;

	head=allocNode(1*2);
	head->next=NULL;

	for(i=2;i<N;i++){
		x=allocNode(i*2);
		insertNext(head,x);
	}

	printf("max:%d\n",max(head));

	return(0);
}
