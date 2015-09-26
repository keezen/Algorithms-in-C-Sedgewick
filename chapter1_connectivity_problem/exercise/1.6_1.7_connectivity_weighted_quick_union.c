#include<stdio.h>

#define N 10

int main(void)
{
	int p,q,ptr[N],size[N];
	int i,j,count;
	FILE *fp;

	fp=fopen("test_data2.dat","r");

	for(i=0;i<=N-1;i++){
		ptr[i]=i;
		size[i]=1;
	}

	while(fscanf(fp,"%d%d",&p,&q)==2){
		count=0;

		for(i=p;count++,ptr[i]!=i;count++,i=ptr[i]);
		for(j=q;count++,ptr[j]!=j;count++,j=ptr[j]);
		if(i==j)
			;
		else{	
			if(size[i]<size[j]){
				count++,ptr[i]=j;
				size[j]+=size[i];
			}else{
				count++,ptr[j]=i;
				size[i]+=size[j];
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
