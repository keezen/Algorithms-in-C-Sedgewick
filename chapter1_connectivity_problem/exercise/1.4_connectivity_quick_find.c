#include<stdio.h>

#define N 10

int main(void)
{
	int p,q,ptr[N];
	int i,temp,count,initializer=0;
	FILE *fp;

	fp=fopen("test_data.dat","r");

	for(i=0;i<=N-1;i++)
		ptr[i]=i;

	while(fscanf(fp,"%d%d",&p,&q)==2){
		count=0;
		if(count+=2,ptr[p]==ptr[q])
			;
		else{
			count++,temp=ptr[p];
			for(i=0;i<=N-1;i++)
				if(count++,ptr[i]==temp)
					count++,ptr[i]=ptr[q];
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
