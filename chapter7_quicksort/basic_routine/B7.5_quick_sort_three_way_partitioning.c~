#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define M 5

void quick_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

/*
** This program is based on partitioning the array into three
** parts: elements smaller than the partitioning element (in a[l]
** ,...,a[j]); elements equal to the partitioning element (in a[j+1]
** ,...,a[i-1]); and elements larger than the partitioning element (
** in a[i],...,a[r]). Then the sort can be completed with two recursive
** calls, one for the smaller keys and one for the larger keys.
*/
void quick_sort(item_t *array,int left,int right)
{ 
	int i,j,k,p,q;
	item_t v=array[right];

	if(right-left+1 <= 1){
		return;
	}

	/*
	** In the partitioning loop, after the scan pointers stop and
	** the items at i and j are exchanged, it checks each of those
	** items to see whether it is equal to the partitioning element
	** . If the one now on the left is equal to the partitioning element,
	** it is exchanged into the left part of the array; if one now on the
	** right is equal to the partitioning element, it is exchanged into the
	** right part of the array.
	*/
	i=left;
	j=right-1;
	p=left-1;
	q=right;
	while(1){
		for(;compare_item(array[i],v)<0;i++)
			;
		for(;compare_item(array[j],v)>0;j--)
			if(j==left)
				break;
		if(i>=j)
			break;

		swap_item(&array[i],&array[j]);
		if(compare_item(array[i],v)==0){
			swap_item(&array[i++],&array[++p]);	
		}
		if(compare_item(array[j],v)==0){
			swap_item(&array[j--],&array[--q]);
		}
	}

	/*
	** If i=j and array[i]=v, it means that array[i] needs to be exchanged
	** to either of the two ends. After this operation, i points to the first
	** element larger than v, and j points to the first element smaller than
	** v.
	*/
	if(i==j && compare_item(array[i],v)==0){
		swap_item(&array[i++],&array[++p]);	
	}	
	/*
	** After the pointers cross, the two ends of the array with elements
	** equal to the partitioning element are exchanged back to the middle.
	** Then those keys are in position and can be excluded from the subfiles
	** for the recursive calls.
	*/
	for(k=left;k<=p;k++,j--){
		swap_item(&array[k],&array[j]);
	}
	for(k=right;k>=q;k--,i++){
		swap_item(&array[k],&array[i]);
	}

	quick_sort(array,left,j);
	quick_sort(array,i,right);
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

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	quick_sort(array,0,N-1);
	print_array(array,N);

	return(0);
}
