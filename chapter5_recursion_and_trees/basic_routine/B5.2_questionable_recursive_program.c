#include<stdio.h>

int puzzle(int N)
{
	printf("puzzle(%d)\n",N);
	
	if(N==1)
		return(1);
	if(N%2==0)
		return(puzzle(N/2));
	
	return(puzzle(3*N+1));
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);

	printf("puzzle(%d):%d\n",N,puzzle(N));

	return(0);
}
