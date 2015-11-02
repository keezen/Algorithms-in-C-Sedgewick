/*
** This program generates N random long capital-letter strings of 30-byte, and then
** count the number of bytes examined by three-way radix quicksort for this file, and
** the number of comparisons by standard quicksort.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

/* The THREE_WAY macro is a flag determining which sorting method is used. */
#define THREE_WAY 1

void print_array(item_t *array,int n_elements);
void three_way_radix_quicksort(item_t *array,int left,int right);
void do_three_way_radix_quicksort(item_t *array,int left,int right,int w);
void quick_sort(item_t *array,int left,int right);
int partition(item_t *array,int left,int right);
void rand_item(item_t *x);

int count_bytes=0;
int count_comp=0;


int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(item_t));
	int i;

	srand((unsigned)time(NULL));	

	for(i=0;i<N;i++){
		rand_item(&array[i]);
	}
//	print_array(array,N);

	#if THREE_WAY

	three_way_radix_quicksort(array,0,N-1);
//	print_array(array,N);
	printf("the number of bytes examined: %d\n",count_bytes);

	#else

	quick_sort(array,0,N-1);
//	print_array(array,N);
	printf("the number of comparisons: %d\n",count_comp);

	#endif

	return(0);
}


void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(&array[i]);
		putchar('\n');
	}
	putchar('\n');
}

void three_way_radix_quicksort(item_t *array,int left,int right)
{
	do_three_way_radix_quicksort(array,left,right,0);
}

void do_three_way_radix_quicksort(item_t *array,int left,int right,int w)
{
	int v;
	int i,j,k;
	int p,q;

	if(right-left+1<=1 || w>=bytesword){
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


	count_bytes+=right-left+1;
	do_three_way_radix_quicksort(array,j+1,i-1,w+1);
	do_three_way_radix_quicksort(array,left,j,w);
	do_three_way_radix_quicksort(array,i,right,w);
}

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

int partition(item_t *array,int left,int right)
{
	item_t v;
	int i,j;

	i=left-1;
	j=right;
	copy_item(&v,&array[right]);
	while(1){
		while((count_comp++,compare_item(&array[++i],&v))<0)
			;
		while((count_comp++,compare_item(&array[--j],&v))>0){
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

void rand_item(item_t *x)
{
	int i;

	for(i=0;i<bytesword;i++){
		(*x)[i]=rand()%26+'A';
	}
}
