/*
** The client program that uses quicksort to sort an
** integer array.
*/
#include<stdio.h>
#include"item.h"

#define N 10

int partition(item_t *array,int left,int right);
void quick_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

/*
** The partition function is a part of quicksort. The variable
** v holds the value of the partitioning element a[r], and i and
** j are the left and right scan pointers, respectively. The pointer
** i scans from left to right and stops when a[i] is larger or equal
** to v. The pointer j scans from right to left and stops when a[i] is
** smaller than v. Then we swap a[i] and a[j] to make sure that the left
** of i is smaller than (or equal to) v, and the right of j is larger
** than (or equal to) v. Repeat this process until i>=j. Finally we swap
** a[i] and a[r], and now no element in the left of a[i] is larger than it,
** and no in the right is smaller than it, so we have done the partition.
*/
int partition(item_t *array,int left,int right)
{
	item_t v=array[right];
	int i,j;

	i=left-1;
	j=right;
	while(1){
		while(compare_item(array[++i],v)<0)
			;
		while(compare_item(array[--j],v)>0){
			if(j==left)
				break;
		}
		if(i>=j)
			break;
		
		swap_item(&array[i],&array[j]);
	}

	swap_item(&array[i],&array[right]);

	return(i);
}


/*
** The quicksort recursive implementation. First, the partition function
** puts a[i] into its final position, where the left side is the elements
** smaller than a[i], and the right side is the elements larger than a[i].
** And then it recursively calls itself to sort the left side, next the right
** side. So the array is sorted at last.
*/
void quick_sort(item_t *array,int left,int right)
{
	int i;

	if(right-left+1 <= 1){
		return;
	}

	i=partition(array,left,right);
	quick_sort(array,left,i-1);
	quick_sort(array,i+1,right);
}

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

int main(void)
{
	item_t array[N];
	int i;

	for(i=0;i<N;i++){
		array[i]=N-i;
	}
	print_array(array,N);

	quick_sort(array,0,N-1);
	print_array(array,N);

	return(0);
}
