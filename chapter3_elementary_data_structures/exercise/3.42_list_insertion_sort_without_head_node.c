#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"list.h"

link_t list_insertion_sort(link_t heada)
{
	link_t x,y,t,headb,before_min,min;
	int min_value;

	min_value=Item(heada);
	before_min=NULL;
	for(x=heada;Next(x)!=NULL;x=Next(x))
		if(Item(Next(x))<min_value){
			min_value=Item(Next(x));
			before_min=x;	
		}
	
	if(before_min!=NULL)
		min=deleteNext(before_min);
	else{
		min=heada;
		heada=Next(heada);
	}

	headb=min;
	headb->next=NULL;

	while(heada!=NULL){	
		t=heada;
		heada=Next(heada);
		
		for(x=headb;Next(x)!=NULL;x=Next(x))
			if(Item(Next(x))>Item(t))
				break;
		insertNext(x,t);
	}

	return(headb);	
}

void print_list(link_t head)
{
	link_t x;
	printf("the list:");
	for(x=head;x!=NULL;x=Next(x))
		printf("%4d ",Item(x));
	putchar('\n');
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]),i;
	link_t heada=NULL,headb=NULL,x,t;

	initNodes(2*N+2);
	srand((unsigned)time(NULL));

	heada=newNode(rand()%1000);
	heada->next=NULL;
	for(x=heada,i=2;i<=N;i++){
		t=newNode(rand()%1000);
		insertNext(x,t);
		x=t;
	}
	print_list(heada);

	headb=list_insertion_sort(heada);
	print_list(headb);	

	return(0);
}
