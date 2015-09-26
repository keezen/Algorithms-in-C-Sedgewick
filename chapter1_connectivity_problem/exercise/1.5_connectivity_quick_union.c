#include<stdio.h>

#define N 10

int main(void)
{
	int p,q,ptr[N];
	int i,j,count;
	FILE *fp;

	fp=fopen("test_data.dat","r");

	for(i=0;i<=N-1;i++)
		ptr[i]=i;
	
	while(fscanf(fp,"%d%d",&p,&q)==2){
		count=0;

		for(i=p;count++,ptr[i]!=i;count++,i=ptr[i]);
		for(j=q;count++,ptr[j]!=j;count++,j=ptr[j]);
		if(i==j)
			;
		else	
			count++,ptr[i]=j;

		printf("%d-%d: ",p,q);
		for(i=0;i<=N-1;i++)
			printf("%d ",(count++,ptr[i]));
		printf("  Times of accessing:%d",count);
		putchar('\n');
	}

	fclose(fp);

	return(0);
}
