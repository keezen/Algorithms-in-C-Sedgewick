#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
int M;

void key_index_count(int array[],int left,int right);
void print_array(int array[],int n_elements);

void key_index_count(int array[],int left,int right)
{
	int count[M];
	int b[N];
	int i;

	for(i=0;i<M;i++){
		count[i]=0;
	}

	for(i=left;i<=right;i++){
		count[array[i]+1]++;
	}

	for(i=1;i<M;i++){
		count[i]+=count[i-1];	
	}

	for(i=left;i<=right;i++){
		b[count[array[i]]++]=array[i];
	}

	for(i=left;i<=right;i++){
		array[i]=b[i-left];
	}
}

void print_array(int array[],int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		printf("%d ",array[i]);
	}
	putchar('\n');
}

int max(int a,int b,int c)
{
	int max;

	max=a;
	if(b>max)
		max=b;
	if(c>max)
		max=c;

	return(max);
}

int main(void)
{
	int array[N];
	int i;
	int a,b,c;

	srand((unsigned)time(NULL));

	a=1;
	b=4;
	c=5;
	for(i=0;i<N;i++){
		switch(rand()%3){
			case 0:
				array[i]=a;
				break;
			case 1:
				array[i]=b;
				break;
			case 2:
				array[i]=c;
				break;
		}
	}
	/*
	** Set M to be the maximum integer of keys a,b,c, and plus 1.
	*/
	M=max(a,b,c)+1;
	print_array(array,N);

	key_index_count(array,0,N-1);
	print_array(array,N);

	return(0);
}
