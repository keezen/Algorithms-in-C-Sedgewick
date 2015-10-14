/*
** The client which uses the merge_ab function to merge two
** ordered arrays into an ordered one.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

#define M 6
#define N 4


void merge_ab(item_t *c,item_t *a,int m,item_t *b,int n);
void bubble_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

void bubble_sort(item_t *array,int left,int right)
{
	int i,j;

	for(i=left;i<right;i++){
		for(j=right;j>i;j--){
			if(compare_item(array[j],array[j-1]) < 0){
				swap_item(&array[j],&array[j-1]);
			}
		}
	}
}

/*
** The merge_ab function combine two ordered arrays a and b into an 
** ordered array c, we use a for loop that puts an element into c at
** each iteration. If a is exhausted, the element comes from b; if b
** is exhausted, the element comes from a; and if items remain in both
** , the smallest of the remaining elements in a and b goes to c.
*/
void merge_ab(item_t *c,item_t *a,int m,item_t *b,int n)
{
	int i,j,k;

	for(i=0,j=0,k=0;k<m+n;k++){
		if(i==m){
			c[k]=b[j++];
			continue;
		}
		if(j==n){
			c[k]=a[i++];
			continue;	
		}

		if(compare_item(a[i],b[j])<=0){
			c[k]=a[i++];
		}else{
			c[k]=b[j++];
		}
	}
}

int main(void)
{
	item_t a[M];
	item_t b[N];
	item_t c[M+N];
	int i;

	srand((unsigned)time(NULL));

	for(i=0;i<M;i++){
		a[i]=rand()%10;
	}
	for(i=0;i<N;i++){
		b[i]=rand()%10;
	}

	bubble_sort(a,0,M-1);
	bubble_sort(b,0,N-1);
	print_array(a,M);
	print_array(b,N);

	merge_ab(c,a,M,b,N);
	print_array(c,M+N);

	return(0);
}
