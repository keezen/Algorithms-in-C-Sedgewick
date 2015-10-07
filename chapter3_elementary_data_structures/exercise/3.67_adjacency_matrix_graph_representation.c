#include<stdio.h>
#include"dirlist.h"

#define V 8

int array[V][V]={0};
link_t head[V];

link_t *convert_matrix_to_list(int array[][V])
{
	int i,j;
	link_t t;

	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			if(array[i][j] && i!=j){
				t=allocNode(j);
				insertNext(head[i],t);
			}

	return(head);
				
}

void print_adjacency_matrix(int array[][V])
{
	int i,j;

	printf("  ");
	for(i=0;i<V;i++)
		printf("%d ",i);
	putchar('\n');

	for(i=0;i<V;i++){
		printf("%d ",i);
		for(j=0;j<V;j++)
			printf("%d ",array[i][j]);
		putchar('\n');
	}
}

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
	int i,j;
	FILE *fp;

	fp=fopen("adjacency_matrix_graph_representation.dat","r");

	for(i=0;i<V;i++)
		array[i][i]=1;
	for(i=0;i<V;i++){
		head[i]=allocNode(i);
		head[i]->next=NULL;
	}

	while(fscanf(fp,"%d%d",&i,&j)==2)
		array[i][j]=array[j][i]=1;

	fclose(fp);
	
	print_adjacency_matrix(array);
	
	convert_matrix_to_list(array);
	print_list(head);

	return(0);
}
