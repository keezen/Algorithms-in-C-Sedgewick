#include<stdio.h>
#include"dirlist.h"

#define V 8

void print_list(link_t head[])
{
	link_t x;
	int i;

	for(i=0;i<V;i++){
		printf("%d:",Item(head[i]));
		for(x=Next(head[i]);x!=NULL;x=Next(x))
			printf("%d ",Item(x));
		putchar('\n');
	}
}

int main(void)
{
	link_t head[V],t;
	int i,j;
	FILE *fp;

	fp=fopen("adjacency_list_graph_representation.dat","r");

	for(i=0;i<V;i++){
		head[i]=allocNode(i);
		head[i]->next=NULL;
	}

	while(fscanf(fp,"%d%d",&i,&j)==2){
		t=allocNode(j);
		insertNext(head[i],t);
	}

	fclose(fp);

	print_list(head);

	return(0);
}
