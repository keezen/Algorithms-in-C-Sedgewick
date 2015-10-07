#include<stdio.h>

#define V 8

int array[V][V]={0},count=0;

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

int number_of_vertices(int a,int b)
{
	int i;

	for(i=0;i<V;i++)
		if(array[a][i]==1 && array[b][i]==1 && i!=a && i!=b)
			count++;

	return(count);
}

int main(void)
{
	int i,j;
	int a=0,b=6;
	FILE *fp;

	fp=fopen("adjacency_matrix_graph_representation.dat","r");

	for(i=0;i<V;i++)
		array[i][i]=1;

	while(fscanf(fp,"%d%d",&i,&j)==2)
		array[i][j]=array[j][i]=1;

	fclose(fp);
	
	print_adjacency_matrix(array);
	
	printf("the number of vertices that %d-c-%d\n is %d.\n",a,b,number_of_vertices(a,b));

	return(0);
}
