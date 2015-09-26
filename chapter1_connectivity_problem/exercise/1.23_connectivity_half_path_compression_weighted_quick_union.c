#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N_MIN 100
#define N_MAX 1000

int main(void)
{
	int p,q,ptr[N_MAX],size[N_MAX],N;
	int i,j,k,count_edge,root_node;
	FILE *fp;

	fp=fopen("objects_edges.dat","w");

	for(N=N_MIN;N<=N_MAX;N++){
		count_edge=0;

		for(i=0;i<=N-1;i++){
			ptr[i]=i;
			size[i]=1;
		}
	
		srand((unsigned)time(NULL));

		while(size[root_node]<N){
			p=rand()%N;
			q=rand()%N;
	
			for(i=p;ptr[i]!=i;i=ptr[i])
				ptr[i]=ptr[ptr[i]];
			for(j=q;ptr[j]!=j;j=ptr[j]);
				ptr[j]=ptr[ptr[j]];
			if(i==j)
				continue;
			
			if(size[i]<size[j]){
				ptr[i]=j;
				size[j]+=size[i];
				root_node=j;
			}else{
				ptr[j]=i;
				size[i]+=size[j];
				root_node=i;
			}
		}

		for(i=0;i<=N-1;i++)
			if(ptr[i]!=i)
				count_edge++;
	
		fprintf(fp,"%d\t%d\n",N,count_edge);

	}

	fclose(fp);

	return(0);
}
