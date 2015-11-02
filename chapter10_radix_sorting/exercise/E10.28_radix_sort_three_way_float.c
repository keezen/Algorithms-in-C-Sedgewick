/*
** This programs implements a three-way radix quicksort for the case where the 
** keys are vectors of t floating point numbers, obviously, t equals to bytesword,
** which you can set yourself.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

void print_array(item_t *array,int n_elements);
void three_way_radix_quicksort(item_t *array,int left,int right);
void do_three_way_radix_quicksort(item_t *array,int left,int right,int w);
void rand_item(item_t *x);

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(item_t));
	int i;

	srand((unsigned)time(NULL));	

	for(i=0;i<N;i++){
		rand_item(&array[i]);
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
	int i,j,k;
	int p,q;
	double v;

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


	do_three_way_radix_quicksort(array,j+1,i-1,w+1);
	do_three_way_radix_quicksort(array,left,j,w);
	do_three_way_radix_quicksort(array,i,right,w);
}

/*
** The rand_item function generates a floating point number between 0 and 1.
*/
void rand_item(item_t *x)
{
	int i;

	for(i=0;i<bytesword;i++){
		(*x)[i]=(double)rand()/RAND_MAX;
	}
}
