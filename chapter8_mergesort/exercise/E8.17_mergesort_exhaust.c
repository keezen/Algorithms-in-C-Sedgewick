#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

void merge(item_t *a,int left,int middle,int right);
void merge_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);

int N;
int count_remain=0;
int flag=0;

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

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
		/*
		** For the file of N elements, when one subfile exhausts
		** , count the number of remained elements of the other
		** subfile.
		*/
		if(n==N && flag==0){
			if(i==middle+1 || j==middle){
				count_remain=right-k+1;
				flag=1;
			}
		}

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
	item_t *array;
	int i;

	N=atoi(argv[1]);
	array=malloc(N*sizeof(*array));
	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}

	merge_sort(array,0,N-1);
	putchar('\n');

	printf("N=%d,remain=%d\n",N,count_remain);

	free(array);

	return(0);
}
