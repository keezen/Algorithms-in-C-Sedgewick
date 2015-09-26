#include<stdio.h>

#define N 10000

int main(void)
{
	int p,q,ptr[N],size[N];
	int i,j;

	for(i=0;i<=N-1;i++){
		ptr[i]=i;
		size[i]=1;
	}

	while(scanf("%d%d",&p,&q)==2){
		for(i=p;ptr[i]!=i;i=ptr[i]);
		for(j=q;ptr[j]!=j;j=ptr[j]);
		if(i==j)
			continue;
			
		if(size[i]<size[j]){
			ptr[i]=j;
			size[j]+=size[i];
		}else{
			ptr[j]=i;
			size[i]+=size[j];
		}
		printf("p-q: %d-%d\n",p,q);
	}

	return(0);
}
