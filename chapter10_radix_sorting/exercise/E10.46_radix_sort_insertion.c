/*
** This program implements three-way radix quicksort such that the insertion sort
** for small files does not use leading bytes that are known to be equal in comparisons.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

#define M 10

void print_array(item_t *array,int n_elements);
void three_way_radix_quicksort(item_t *array,int left,int right);
void do_three_way_radix_quicksort(item_t *array,int left,int right,int w);
void insertion_sort_radix(item_t *array,int left,int right,int w);
void insertion_sort_byte(item_t *array,int left,int right,int byte);


int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(item_t));
	int i;

	srand((unsigned)time(NULL));	

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	three_way_radix_quicksort(array,0,N-1);
	print_array(array,N);

	return(0);
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

void three_way_radix_quicksort(item_t *array,int left,int right)
{
	do_three_way_radix_quicksort(array,left,right,0);
}

/*
** This three-way radix quicksort uses a cutoff that uses a specific insertion sort
** for small files.
*/
void do_three_way_radix_quicksort(item_t *array,int left,int right,int w)
{
	int v;
	int i,j,k;
	int p,q;

	if(w>=bytesword){
		return;
	}
	if(right-left+1<=M){
		insertion_sort_radix(array,left,right,w);
		return;
	}

	i=left;
	j=right-1;
	p=left-1;
	q=right;
	v=digit(array[right],w);
	while(1){
		for(;digit(array[i],w)<v;i++)
			;
		for(;j>=left && digit(array[j],w)>v;j--)
			;

		if(i>=j){
			break;	
		}

		swap_item(&array[i],&array[j]);		
		if(digit(array[i],w) == v){
			swap_item(&array[i],&array[++p]);
		}
		if(digit(array[j],w) == v){
			swap_item(&array[j],&array[--q]);
		}

		i++;
		j--;
	}

	if(i==j && digit(array[i],w)==v){
		swap_item(&array[i++],&array[++p]);
	}


	for(k=left;k<=p;k++){
		swap_item(&array[k],&array[j--]);
	}
	for(k=right;k>=q;k--){
		swap_item(&array[k],&array[i++]);
	}


	do_three_way_radix_quicksort(array,j+1,i-1,w+1);
	do_three_way_radix_quicksort(array,left,j,w);
	do_three_way_radix_quicksort(array,i,right,w);
}

/*
** The insertion_sort_radix functions sorts the array according to the
** w trailing bytes, using a strategy like the LSD radix sort. Whereas
** the key-indexed counting method is replaced by a stable insertion sort.
*/
void insertion_sort_radix(item_t *array,int left,int right,int w)
{
	int i;

	for(i=bytesword-1;i>=w;i--){
		insertion_sort_byte(array,left,right,i);
	}
}

/*
** This insertion_sort_byte function sorts the array according to the given
** byte that is indicated by the parameter int byte.
*/
void insertion_sort_byte(item_t *array,int left,int right,int byte)
{
	int i,j;
	item_t t;

	for(i=left+1;i<=right;i++){
		if(digit(array[i],byte)<digit(array[left],byte)){
			swap_item(&array[i],&array[left]);
		}
	}

	for(i=left+2;i<=right;i++){
		copy_item(&t,&array[i]);

		for(j=i-1;digit(array[j],byte)>digit(t,byte);j--){
			copy_item(&array[j+1],&array[j]);
		}

		copy_item(&array[j+1],&t);
	} 
}
