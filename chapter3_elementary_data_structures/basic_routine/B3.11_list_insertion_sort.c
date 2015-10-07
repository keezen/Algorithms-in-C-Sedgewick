#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node* link_t;

struct node{
	int item;
	link_t next;
};

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]),i;
	link_t heada,headb,x,t;

	heada=malloc(sizeof(struct node));
	heada->next=NULL;		
	headb=malloc(sizeof(struct node));
	headb->next=NULL;

	srand((unsigned)time(NULL));

	for(x=heada,i=1;i<=N;i++){
		t=x;
		x=malloc(sizeof(struct node));
		x->next=t->next;
		t->next=x;

		x->item=rand()%1000;
	}

	while(heada->next!=NULL){
		t=heada->next;
		heada->next=heada->next->next;

		for(x=headb;x->next!=NULL && x->next->item<=t->item;x=x->next);
		t->next=x->next;
		x->next=t;
	}

	printf("list sorted:");
	for(x=headb->next;x!=NULL;x=x->next)
		printf("%3d ",x->item);
	putchar('\n');		

	return(0);
}
