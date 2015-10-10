#include<stdio.h>
#include<stdlib.h>

#define UNKNOWN -1

int *knownP;

int P(int N)
{	
	if(knownP[N]!=UNKNOWN)
		return(knownP[N]);

	if(N==0)
		return(knownP[N]=0);
	if(N==1)
		return(knownP[N]=1);
	
	return(knownP[N]=N/2+P(N/2)+P(N-N/2));
}

int main(int argc,char *argv[])
{
	int i;
	int Nmax=atoi(argv[1]);
	FILE *fp;
	
	fp=fopen("top_down_dynamic_programming.dat","w");

	knownP=malloc((Nmax+1)*sizeof(int));
	for(i=0;i<=Nmax;i++)
		knownP[i]=UNKNOWN;

	for(i=0;i<=Nmax;i++)
	fprintf(fp,"%d\t%d\n",i,P(i));

	fclose(fp);

	return(0);
}
