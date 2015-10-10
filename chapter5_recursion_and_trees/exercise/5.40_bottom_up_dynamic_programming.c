#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define UNKNOWN -1

int *knownP;

int P(int N)
{	
	int x,y;

	if((x=knownP[N]) != UNKNOWN)
		return(knownP[N]);
	
	if((x=knownP[N/2])!=UNKNOWN && (y=knownP[N-N/2])!=UNKNOWN)
		return(knownP[N]=N/2+x+y);
}

int main(int argc,char *argv[])
{
	int i;
	int Nmax=atoi(argv[1]);
	FILE *fp;
	
	fp=fopen("bottom_up_dynamic_programming.dat","w");

	knownP=malloc((Nmax+1)*sizeof(int));
	for(i=0;i<=Nmax;i++)
		knownP[i]=UNKNOWN;
	knownP[0]=0;
	knownP[1]=1;

	fprintf(fp,"%d\t%f\n",0,0.0);
	for(i=1;i<=Nmax;i++)
		fprintf(fp,"%d\t%f\n",i,P(i)-i*log(i/2.0)/log(2));

	fclose(fp);

	return(0);
}
