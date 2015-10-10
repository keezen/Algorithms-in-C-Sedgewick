#include<stdio.h>
#include<stdlib.h>

#define UNKNOWN -1

double *C;

void calculate_Cn(int Nmax)
{	
	int N,k;

	C[0]=1;
	for(N=1;N<=Nmax;N++){
		C[N]=0;

		for(k=1;k<=N;k++)
			C[N]+=C[k-1]+C[N-k];
		C[N]/=N;
		C[N]+=N;	
	}
}

int main(int argc,char *argv[])
{
	int i;
	int Nmax=atoi(argv[1]);
	FILE *fp;
	
	fp=fopen("bottom_up_dynamic_programming.dat","w");

	C=malloc((Nmax+1)*sizeof(double));
	for(i=0;i<=Nmax;i++)
		C[i]=UNKNOWN;

	calculate_Cn(Nmax);

	for(i=0;i<=Nmax;i++)
		fprintf(fp,"%d\t%f\n",i,C[i]);

	fclose(fp);

	return(0);
}
