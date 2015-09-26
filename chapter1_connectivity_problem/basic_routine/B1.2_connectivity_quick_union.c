#include<stdio.h>

#define N 10

int main(void)
{
	int p,q,ptr[N];
	int i,j;

	for(i=0;i<=N-1;i++)
		ptr[i]=i;
	
	while(scanf("%d%d",&p,&q)==2){
		for(i=p;ptr[i]!=i;i=ptr[i]);
		for(j=q;ptr[j]!=j;j=ptr[j]);
		if(i==j)
			continue;
			
		ptr[i]=j;
		printf("p-q: %d-%d\n",p,q);
	}

	return(0);
}
