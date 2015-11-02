/*
** This program calculates the runtime of different byte size for N random 64-bit keys, using
** three-way radix quicksort.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

void print_array(item_t *array,int n_elements);
void three_way_radix_quicksort(item_t *array,int left,int right);
void do_three_way_radix_quicksort(item_t *array,int left,int right,int w);
long long rand_64(void);

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(item_t));
	int i;
	clock_t c1,c2;

	srand((unsigned)time(NULL));	

	for(i=0;i<N;i++){
		array[i]=rand_64();
	}
//	print_array(array,N);

	c1=clock();
	three_way_radix_quicksort(array,0,N-1);
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

void three_way_radix_quicksort(item_t *array,int left,int right)
{
	do_three_way_radix_quicksort(array,left,right,0);
}

void do_three_way_radix_quicksort(item_t *array,int left,int right,int w)
{
	long long v;
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


	do_three_way_radix_quicksort(array,j+1,i-1,w+1);
	do_three_way_radix_quicksort(array,left,j,w);
	do_three_way_radix_quicksort(array,i,right,w);
}

long long rand_64(void)
{
	long long a=rand();
	long long b=rand();

	a=a<<32;

	b=b<<1;
	a+=b;
	a+=rand()%1;

	return(a);
}
