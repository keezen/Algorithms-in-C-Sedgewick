#include<stdio.h>
#include<stdlib.h>
#include"item.h"

#define N 10

void merge(item_t *a,int left,int middle,int right);
void merge_sort(item_t *array,int left,int right);
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

/*
** This mergesort is used to sort strings. As you see, the code is completely the 
** same as which is used to sort integers. The only change you should make is
** changing the item_t in item.h to string type, that is char *. Accordingly
** the implementation of item.h should be changed. But it is simple to get, so
** this is the advantage of using abstract item type, instead of apparent type
** such as int.
*/
void merge(item_t *a,int left,int middle,int right)
{
	int n=right-left+1;
	item_t *aux=malloc(n*sizeof(*aux));
	int i,j,k;
	
	for(k=0,i=left;i<=middle;i++){
		aux[k++]=a[i];
	}
	for(i=right;i>middle;i--){
		aux[k++]=a[i];
	}

	for(i=0,j=n-1,k=left;k<=right;k++){
		if(compare_item(aux[i],aux[j])<0){
			a[k]=aux[i++];	
		}else{
			a[k]=aux[j--];	
		}
	}

	free(aux);
}

void merge_sort(item_t *array,int left,int right)
{
	int middle=(left+right)/2;	

	if(right-left+1<=1){
		return;
	}

	merge_sort(array,left,middle);
	merge_sort(array,middle+1,right);
	merge(array,left,middle,right);
}

int main(int argc,char *argv[])
{
	item_t array[N]={
		"Adams",
		"Smith",
		"Washington",
		"Jackson",
		"Black",
		"White",
		"Wilson",
		"Thompson",
		"Brown",
		"Jones"
	};

	print_array(array,N);

	merge_sort(array,0,N-1);
	print_array(array,N);	

	return(0);
}
