#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

void print_array(item_t *array,int n_elements);
void binary_quicksort(item_t *array,int left,int right);
void do_binary_quicksort(item_t *array,int left,int right,int w);
int rand_format(void);

int rand_max=0x10000;

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;
	clock_t c1,c2;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand_format();
	}
//	print_array(array,N);

	c1=clock();
	binary_quicksort(array,0,N-1);
	c2=clock();
//	print_array(array,N);
	printf("sorted time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

	return(0);
}

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar('\n');
	}
	putchar('\n');
}

/*
** The modified binary quicksort that will check explicitly for the case that
** all keys are equal.
*/
void binary_quicksort(item_t *array,int left,int right)
{
	int i,j;

	for(i=left+1;i<=right;i++){
		for(j=0;j<bytesword;j++){
			if(digit(array[i],j)!=digit(array[i-1],j)){
				break;
			}
		}

		if(j!=bytesword){
			break;
		}
	}

	if(i==right+1){
		return;
	}

	do_binary_quicksort(array,left,right,0);
}

void do_binary_quicksort(item_t *array,int left,int right,int w)
{
	int i,j;

	if(right-left+1<=1 || w>=bytesword){
		return;
	}


	i=left;
	j=right;
	while(1){
		for(;i<=right && digit(array[i],w)!=1;i++)
			;
		for(;j>=left && digit(array[j],w)!=0;j--)
			;

		if(i>=j){
			break;
		}

		swap_item(&array[i],&array[j]);
		i++;
		j--;
	}

	do_binary_quicksort(array,left,i-1,w+1);
	do_binary_quicksort(array,i,right,w+1);
}

/*
** This function will generate a 32-bit integer of the specific format: the
** rightmost 16 bits are uniformly random, and the leftmost 16 bits are all 0
** except with a 1 in position i if there are i 1s in the right half.
*/
int rand_format(void)
{
	int right,left;
	int sum_right;
	int i;

	right=rand()%rand_max;

	for(sum_right=0,i=0;i<16;i++){
		sum_right+=(right >> i) & 1;
	}

	left=0x00000001;
	if(sum_right>0){
		left=left << (32-sum_right);
	}else{
		left=0;
	}

	return(left | right);
}
