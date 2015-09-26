#include<stdio.h>

#define N 10000

int main(void)
{
	int p,q,ptr[N];
	int i,temp;

	for(i=0;i<=N-1;i++)
		ptr[i]=i;

	while(fscanf(fp,"%d%d",&p,&q)==2){
		if(ptr[p]==ptr[q])
			continue;
		
		temp=ptr[p];
		for(i=0;i<=N-1;i++)
			if(ptr[i]==temp)
				ptr[i]=ptr[q];
		printf("p-q: %d-%d\n",p,q);
	}

	return(0);
}
