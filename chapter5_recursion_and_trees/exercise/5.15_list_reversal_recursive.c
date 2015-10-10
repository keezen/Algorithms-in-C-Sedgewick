#include<stdio.h>
#include<stdlib.h>
#include"dirlist.h"

link_t r=NULL;

link_t reverse_list(link_t head)
{
	link_t t=head->next,reve;

	if(t==NULL){
		head->next=r;
		return(head);
	}
	
	head->next=r;
	r=head;

	reve=reverse_list(t);
	t->next=head;
		
	return(reve);
}

void printList(link_t head)
{
	link_t x;
	for(x=head;x!=NULL;x=Next(x))
		printf("%d ",Item(x));
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int i;
	link_t x,t,head,reve;

	head=allocNode(1);
	head->next=NULL;

	for(x=head,i=2;i<=N;i++){
		t=allocNode(i);
		insertNext(x,t);
		x=t;
	}

	printf("original list:");
	printList(head);
	putchar('\n');

	reve=reverse_list(head);

	printf("reversed list:");
	printList(reve);
	putchar('\n');

	return(0);
}
