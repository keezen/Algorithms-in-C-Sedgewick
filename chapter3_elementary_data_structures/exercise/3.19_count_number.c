#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 1000

int main(void)
{
	int count[N]={0},number_of_positive_integers=0,number_of_satisfied_values=0,x;

	srand((unsigned)time(NULL));

	while(number_of_satisfied_values<N){
		x=rand()%N;
		number_of_positive_integers++;

		if(count[x]==0){
			number_of_satisfied_values++;
		}
		count[x]++;	
	}

	printf("the number of positive integers when each value at least once:%d\n",number_of_positive_integers);

	return(0);
}
