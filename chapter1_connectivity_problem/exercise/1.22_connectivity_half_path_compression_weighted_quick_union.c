#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 1000

int main(void)
{
	int p,q,ptr[N],size[N];
	int i,j,count_union=0,count_edge=0;

	for(i=0;i<=N-1;i++){
		ptr[i]=i;
		size[i]=1;
	}

	srand((unsigned)time(NULL));

	while(count_union<N-1){
		p=rand()%N;
		q=rand()%N;

		for(i=p;ptr[i]!=i;i=ptr[i])
			ptr[i]=ptr[ptr[i]];
		for(j=q;ptr[j]!=j;j=ptr[j]);
			ptr[j]=ptr[ptr[j]];
		if(i==j)
			continue;

		count_union++;			
		if(size[i]<size[j]){
			ptr[i]=j;
			size[j]+=size[i];
		}else{
			ptr[j]=i;
			size[i]+=size[j];
		}
	}

	for(i=0;i<=N-1;i++)
		if(ptr[i]!=i)
			count_edge++;
	printf("the number of edges: %d\n",count_edge);

	return(0);
}
