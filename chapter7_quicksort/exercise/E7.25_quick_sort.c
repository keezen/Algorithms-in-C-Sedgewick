#include<stdio.h>
#include<stdlib.h>
#include"item.h"

#define N 10
#define M 3  /* The subfile cutoff less than which the subfile will be insertion-sorted. */

int partition(item_t *array,int left,int right);
void insertion_sort(item_t *array,int left,int right);
void quick_sort(item_t *array,int left,int right);
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

void insertion_sort(item_t *array,int left,int right)
{
	int i,j;
	item_t temp;

	for(i=left+1;i<=right;i++)
		if(compare_item(array[i],array[left]) < 0)
			swap_item(&array[i],&array[left]);

	for(i=left+2;i<=right;i++){
		temp=array[i];

		for(j=i-1;compare_item(array[j],temp) > 0;j--){
			array[j+1]=array[j];
		}

		array[j+1]=temp;
	} 
}

void quick_sort(item_t *array,int left,int right)
{
	int i;

	if(right-left+1 <= M){
		insertion_sort(array,left,right);
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
	item_t array[N]={
		{"Wilson",3},
		{"White",3},
		{"Washington",2},
		{"Thompson",4},
		{"Smith",1},
		{"Jones",4},
		{"Jackson",2},
		{"Brown",4},
		{"Black",2},
		{"Adams",1}
	};
	int i;

	print_array(array,N);

	quick_sort(array,0,N-1);
	print_array(array,N);

	return(0);
}
