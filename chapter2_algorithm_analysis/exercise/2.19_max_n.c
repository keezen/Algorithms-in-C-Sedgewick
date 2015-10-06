#include<stdio.h>
#include<math.h>

#define NUMBER_OF_INSTRUCTIONS 1000000
#define NUMBER_OF_FUNCTIONS 5

typedef double function_t(int n);

double function_0(int n)
{
	return(pow(n,1.5));
}

double function_1(int n)
{
	return(pow(n,5.0/4));
}

double function_2(int n)
{
	double harmonic_number=log(n)+0.57721;
	return(2*n*harmonic_number);
}

double function_3(int n)
{
	return(n*log(n)/log(2)*log(log(n)/log(2))/log(2));
}

double function_4(int n)
{
	return(n*n*log(n)/log(2));
}

int main(void)
{
	int i,j,n[NUMBER_OF_FUNCTIONS];
	function_t *function_pointer[NUMBER_OF_FUNCTIONS]={function_0,function_1,function_2,function_3,function_4};

	for(i=0;i<NUMBER_OF_FUNCTIONS;i++){
		for(j=2;function_pointer[i](j)<=NUMBER_OF_INSTRUCTIONS;j++);
		n[i]=j-1;
	}

	for(i=0;i<NUMBER_OF_FUNCTIONS;i++)
		printf("n[%d]: %d\n",i,n[i]);

	return(0);
}
