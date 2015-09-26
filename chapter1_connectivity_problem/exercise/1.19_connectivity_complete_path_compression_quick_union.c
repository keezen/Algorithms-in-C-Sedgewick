#include<stdio.h>

#define N 10

int main(void)
{
	int p,q,ptr[N];
	int i,j,k,temp,root_node,count;
	FILE *fp;

	fp=fopen("1.19_test_data.dat","r");

	for(i=0;i<=N-1;i++){
		ptr[i]=i;
	}

	while(fscanf(fp,"%d%d",&p,&q)==2){
		count=0;

		for(i=p;count++,ptr[i]!=i;count++,i=ptr[i]);
		for(j=q;count++,ptr[j]!=j;count++,j=ptr[j]);

		if(i==j)
			;
		else{
			ptr[i]=j;
			root_node=j;	

			k=p;
			while(count++,ptr[k]!=k){
				count++,temp=ptr[k];
				count++,ptr[k]=root_node;
				k=temp;
			}
	
			k=q;
			while(count++,ptr[k]!=k){
				count++,temp=ptr[k];
				count++,ptr[k]=root_node;
				k=temp;
			}

		}

		printf("%d-%d: ",p,q);
		for(i=0;i<=N-1;i++)
			printf("%d ",(count++,ptr[i]));
		printf("  Times of accessing:%d",count);
		putchar('\n');
	}

	fclose(fp);

	return(0);
}
