#include<stdio.h>

#define N 10

int main(void)
{
	int p,q,ptr[N],size[N];
	int i,j,k,temp,root_node;

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
			root_node=j;
		}else{
			ptr[j]=i;
			size[i]+=size[j];
			root_node=i;
		}

		k=p;
		while(ptr[k]!=k){
			temp=ptr[k];
			ptr[k]=root_node;
			k=temp;
		}

		k=q;
		while(ptr[k]!=k){
			temp=ptr[k];
			ptr[k]=root_node;
			k=temp;
		}

		printf("p-q: %d-%d\n",p,q);
	}

	return(0);
}
