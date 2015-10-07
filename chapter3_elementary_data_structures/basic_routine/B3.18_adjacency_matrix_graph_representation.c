#include<stdio.h>

#define V 8

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

int main(void)
{
	int array[V][V]={0},i,j;
	FILE *fp;

	fp=fopen("adjacency_matrix_graph_representation.dat","r");

	for(i=0;i<V;i++)
		array[i][i]=1;

	while(fscanf(fp,"%d%d",&i,&j)==2)
		array[i][j]=array[j][i]=1;

	fclose(fp);
	
	print_adjacency_matrix(array);

	return(0);
}
