/*
** This program generates N random 80-byte keys with R=256, and sorts them with 
** two different methods: MSD radix sort and three-way radix quicksort. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

/* The macro THREE_WAY is a flag indicating which method is to be used. */
#define THREE_WAY 1

void print_array(item_t *array,int n_elements);
void radix_sort(item_t *array,int left,int right);
void do_three_way_radix_quicksort(item_t *array,int left,int right,int w);
void do_msd_radixsort(item_t *array,int left,int right,int w);
void rand_item(item_t *x);

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(item_t));
	int i;
	clock_t c1,c2;

	srand((unsigned)time(NULL));	

	for(i=0;i<N;i++){
		rand_item(&array[i]);
	}
//	print_array(array,N);

	c1=clock();
	radix_sort(array,0,N-1);
	c2=clock();
//	print_array(array,N);
	printf("sorted time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

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

void radix_sort(item_t *array,int left,int right)
{
	#if THREE_WAY
	do_three_way_radix_quicksort(array,left,right,0);
	#else
	do_msd_radixsort(array,left,right,0);
	#endif
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


	do_three_way_radix_quicksort(array,j+1,i-1,w+1);
	do_three_way_radix_quicksort(array,left,j,w);
	do_three_way_radix_quicksort(array,i,right,w);
}

void do_msd_radixsort(item_t *array,int left,int right,int w)
{
	int n=right-left+1;
	item_t *aux;
	int count[R+1];
	int i;

	if(right-left+1<=1 || w>=bytesword){
		return;
	}


	for(i=0;i<=R;i++){
		count[i]=0;
	}

	for(i=left;i<=right;i++){
		count[digit(array[i],w)+1]++;
	}

	for(i=1;i<=R;i++){
		count[i]+=count[i-1];
	}


	aux=malloc(n*sizeof(*aux));

	for(i=left;i<=right;i++){
		copy_item(&aux[count[digit(array[i],w)]++],&array[i]);
	}

	for(i=left;i<=right;i++){
		copy_item(&array[i],&aux[i-left]);	
	}

	free(aux);

	
	do_msd_radixsort(array,left,left+count[0]-1,w+1);
	for(i=1;i<R;i++){
		do_msd_radixsort(array,left+count[i-1],left+count[i]-1,w+1);		
	}
}

void rand_item(item_t *x)
{
	int i;

	for(i=0;i<bytesword;i++){
		(*x)[i]=rand()%R;
	}
}
