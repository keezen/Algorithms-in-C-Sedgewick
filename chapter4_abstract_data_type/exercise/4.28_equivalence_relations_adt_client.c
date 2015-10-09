#include<stdio.h>

int main(int argc,char *argv[])
{	
	int N=atoi(argv[1]);
	int p,q,x=3;
	FILE *fp;

	fp=fopen("equivalence_relations_adt_client.dat","r");	

	UFinit(N);
	
	while(fscanf(fp,"%d%d",&p,&q)==2){
		if(!UFfind(p,q)){
			UFunion(p,q);
			printf("%d\t%d\n",p,q);
		}	
	}

	fclose(fp);

	printf("number of connected nodes of %d:%d\n",x,count_connected_nodes(x));

	return(0);
}
