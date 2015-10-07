#include<stdio.h>

#define N 10

int main(void)
{
	int count[N]={0},number,i;
	FILE *fp;

	fp=fopen("count_number.dat","r");

	while(fscanf(fp,"%d",&number)==1){
		if(number<N)
			count[number]++;
	}

	fclose(fp);

	for(i=0;i<N;i++)
		printf("count[%d]:%d\n",i,count[i]);

	return(0);
}
