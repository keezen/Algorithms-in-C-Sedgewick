#include<stdio.h>

int power(int a,int b)
{
	int i,power=1;

	for(i=1;i<=b;i++)
		power*=a;

	return(power);
	
}

int main(void)
{
	int n=10000,ceil,i;

	for(i=0;n>power(2,power(2,i));i++);
	ceil=i;

	printf("ceil of lglgN:%d\n",ceil);	

	return(0);
}
