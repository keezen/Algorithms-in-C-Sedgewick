#include<stdio.h>
#include"dirlist.h"

#define V 8

link_t head[V];
int count=0;

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

int number_of_vertices(int a,int b)
{
	link_t t,s;

	for(t=Next(head[a]);t!=NULL;t=Next(t))
		for(s=Next(head[b]);s!=NULL;s=Next(s))
			if(Item(t)==Item(s))
				count++;

	return(count);
}

int main(void)
{
	link_t t;
	int i,j,a=0,b=6;
	FILE *fp;

	fp=fopen("adjacency_list_graph_representation.dat","r");

	for(i=0;i<V;i++){
		head[i]=allocNode(i);
		head[i]->next=NULL;
	}

	while(fscanf(fp,"%d%d",&i,&j)==2){
		t=allocNode(j);
		insertNext(head[i],t);
		t=allocNode(i);
		insertNext(head[j],t);
	}

	fclose(fp);

	print_list(head);
	printf("the number of vertices that %d-c-%d\n is %d.\n",a,b,number_of_vertices(a,b));

	return(0);
}
