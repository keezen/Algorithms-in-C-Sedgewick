#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define N 10
#define M 5

void key_index_count(int array[],int left,int right);
void print_array(int array[],int n_elements);

/*
** This function will sort the array, whose key can be
** used as index, ranging from 0 to M-1.
*/
void key_index_count(int array[],int left,int right)
{
	int count[M];
	int b[N];
	int i;

	/*
	** This for loop initializes the counts to 0.
	*/
	for(i=0;i<M;i++){
		count[i]=0;
	}

	/*
	** This for loop sets the count[i] to the number
	** of keys (i-1).
	*/
	for(i=left;i<=right;i++){
		count[array[i]+1]++;
	}

	/*
	** This for loop add numbers, to make count[i] have the
	** number of keys less than i. count[i] is also the start
	** position where the key i is in the final file.
	*/
	for(i=1;i<M;i++){
		count[i]+=count[i-1];	
	}

	/*
	** This loop moves the keys into an auxiliary array b according
	** the counts.
	*/
	for(i=left;i<=right;i++){
		b[count[array[i]]++]=array[i];
	}

	/*
	** This loop moves the sorted file back into the original array.
	*/
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

int main(void)
{
	int array[N];
	int i;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%M;
	}
	print_array(array,N);

	key_index_count(array,0,N-1);
	print_array(array,N);

	return(0);
}
