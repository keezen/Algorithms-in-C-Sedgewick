#include<stdio.h>
#include<stdlib.h>

#define UNKNOWN -1

double *knownC;

double C(int N)
{	
	int k;
	double result=0;

	if(knownC[N]>=0)
		return(knownC[N]);

	if(N==0)
		return(knownC[N]=1);

	for(k=1;k<=N;k++)
		result+=C(k-1)+C(N-k);
	result=result/N+N;
	
	return(knownC[N]=result);
}

int main(int argc,char *argv[])
{
	int i;
	int Nmax=atoi(argv[1]);
	FILE *fp;
	
	fp=fopen("bottom_up_dynamic_programming.dat","w");

	knownC=malloc((Nmax+1)*sizeof(double));
	for(i=0;i<=Nmax;i++)
		knownC[i]=UNKNOWN;

	for(i=0;i<=Nmax;i++)
		fprintf(fp,"%d\t%f\n",i,C(i));

	fclose(fp);

	return(0);
}
