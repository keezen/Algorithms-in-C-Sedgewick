#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef int number_t;

number_t random_number(void)
{
	int r=2;
	return(rand()%r);
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]),i;
	double average=0,standard_deviation=0;
	number_t x;

	srand((unsigned)time(NULL));
	for(i=1;i<=N;i++){
		x=random_number();
		average+=(double)x/N;
		standard_deviation+=(double)x*x/N;
	}
	standard_deviation=sqrt(standard_deviation-average*average);

	printf("average:%f\n",average);
	printf("standard_deviation:%f\n",standard_deviation);

	return(0);
}
