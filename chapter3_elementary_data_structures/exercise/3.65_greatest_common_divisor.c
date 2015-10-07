#include<stdio.h>

#define M 10
#define N 10

int greatest_common_divisor(int a,int b)
{
	int t;	

	if(a<b){
		t=a;a=b;b=t;
	}

	if(b==0)
		return(0);

	while(a%b){
		t=b;
		b=a%b;
		a=t;
	}
	if(b==1)
		return(1);
	return(0);
}

void print_array(int array[][N])
{
	int i,j;

	printf("  ");
	for(i=0;i<N;i++)
		printf("%d ",i);
	putchar('\n');

	for(i=0;i<M;i++){
		printf("%d ",i);
		for(j=0;j<N;j++)
			printf("%d ",array[i][j]);
		putchar('\n');
	}
}

int main(void)
{
	int array[M][N],i,j;

	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			if(greatest_common_divisor(i,j)==1)
				array[i][j]=1;
			else
				array[i][j]=0;

	print_array(array);

	return(0);
}
