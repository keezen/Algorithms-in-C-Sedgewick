#include<stdio.h>
#include<math.h>

int main(void)
{
	int i;
	int n1,n2,n3,n4;

	for(i=1;log(i)/log(2)*log(i)/log(2)/2<=sqrt(i);i++);
	n1=i-1;
	
	for(;log(i)/log(2)*log(i)/log(2)/2>sqrt(i);i++);
	n2=i;

	for(i=1;sqrt(i)>log(i)/log(2)*log(i)/log(2)*2;i++);
	n3=i;

	for(;sqrt(i)<=log(i)/log(2)*log(i)/log(2)*2;i++);
	n4=i-1;

	printf("n1: %d\n",n1);
	printf("n2: %d\n",n2);
	printf("n3: %d\n",n3);
	printf("n4: %d\n",n4);

	return(0);
}
