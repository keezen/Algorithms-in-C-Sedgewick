#include<stdio.h>

int main(void)
{
	int N,i,j,array[1000]={0},count=0;
	FILE *fp;

	fp=fopen("n-the_number_of_primes.dat","w");

	for(N=1;N<=1000;N++){
		count=0;

		for(i=2;i<N;i++)
			array[i]=1;
	
		for(i=2;i<=N-1;i++)
			if(array[i]==1)
				for(j=2;j*i<N;j++)
					array[j*i]=0;
	
		for(i=2;i<N;i++)
			if(array[i]==1)
				count++;
	
		fprintf(fp,"%4d\t%4d\n",N,count);
	}

	fclose(fp);

	return(0);
}
