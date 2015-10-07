#include<stdio.h>
#include<stdlib.h>

int V;

int **malloc2d(int r,int c)
{
	int **t,i;
	
	t=malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
		t[i]=malloc(c*sizeof(int));

	return(t);
}

void print_adjacency_matrix(int **array)
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

int main(int argc,char *argv[])
{
	
	int i,j,**array;
	FILE *fp;

	V=atoi(argv[1]);
	array=malloc2d(V,V);
	
	fp=fopen("adjacency_matrix_graph_representation.dat","r");

	for(i=0;i<V;i++)
		array[i][i]=1;

	while(fscanf(fp,"%d%d",&i,&j)==2)
		array[i][j]=array[j][i]=1;

	fclose(fp);
	
	print_adjacency_matrix(array);

	return(0);
}
