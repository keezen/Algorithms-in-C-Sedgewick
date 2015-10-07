#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 1000

int main(void)
{
	int count[N]={0},number=0,x;

	srand((unsigned)time(NULL));

	while(1){
		x=rand()%N;
		number++;

		count[x]++;
		if(count[x]>=2)
			break;
	}

	printf("the number of positive integers when repeating:%d\n",number);

	return(0);
}
