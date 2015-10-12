/*
** Rearrange a file such that all the elements with keys equal
** to the median are in place, with smaller elements to the left
** and larger elements to the right.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

int partition(item_t *array,int left,int right);
int partition_three_way(item_t *array,int left,int right);
void selection(item_t *array,int left,int right,int k);
void print_array(item_t *array,int n_elements);

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

int partition_three_way(item_t *array,int left,int right)
{
	int i,j,k,l,p,q;
	item_t v=array[right];

	if(right-left+1 <= 1){
		return;
	}

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

	if(i==j && compare_item(array[i],v)==0){
		swap_item(&array[i++],&array[++p]);	
	}

	for(k=left;k<=p;k++,j--){
		swap_item(&array[k],&array[j]);
	}
	for(l=j,k=right;k>=q;k--,i++){
		swap_item(&array[k],&array[i]);
	}

	return(l);
}

void selection(item_t *array,int left,int right,int k)
{
	int i;	

	if(right-left+1<=1){
		return;
	}

	i=partition(array,left,right);
	if(i==k){
		return;
	}
	if(i>k){
		selection(array,left,i-1,k);
	}
	if(i<k){
		selection(array,i+1,right,k);
	}
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
	int k=(N-1)/2;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	selection(array,0,N-1,k);
	print_array(array,N);

	swap_item(&array[k],&array[N-1]);
	partition_three_way(array,0,N-1);
	print_array(array,N);
	putchar('\n');
	printf("the %dth smallest item is %d.\n",k+1,array[k]);

	free(array);

	return(0);
}
