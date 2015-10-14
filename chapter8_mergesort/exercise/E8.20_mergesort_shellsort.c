#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

void merge(item_t *a,int left,int middle,int right);
void merge_sort(item_t *array,int left,int right);
int shell_sort(item_t *array,int left,int right);
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

void merge(item_t *a,int left,int middle,int right)
{
	int n=right-left+1;
	item_t *aux;
	int i,j,k;
	
	if(a[middle]<=a[middle+1]){
		return;
	}

	aux=malloc(n*sizeof(*aux));

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

/*
** Mergesort combined with shellsort, in which we firstly shellsort
** the array to make it h-sorted, then we merge these h subfiles.
*/
void merge_sort(item_t *array,int left,int right)
{
	int i,j,k;
	int h;
	int n=right-left+1;
	int *nodes;
	item_t *aux;
	clock_t c3,c4,c5,c6;

	if(right-left+1<=1){
		return;
	}
	
	/*
	** Shellsort the array to make it h-sorted (h==13 in this program).
	*/
	h=shell_sort(array,left,right);	
	nodes=malloc(h*sizeof(*nodes));
	aux=malloc(n*sizeof(*aux));

	/*
	** Merge the h subfiles. First copy the elements from array to the
	** aux array, divided to h parts. Then merge in place the h parts.
	** Finally copy the elements back to the original array.
	*/
	for(k=0,i=0;i<h;i++){
		for(j=i+left;j<=right;j+=h){
			aux[k++]=array[j];
		}
		nodes[i]=k-1;
	}
	for(i=0;i<h-1;i++){
		merge(aux,0,nodes[i],nodes[i+1]);
	}
	for(i=left;i<=right;i++){
		array[i]=aux[i-left];
	}

	free(nodes);
	free(aux);
}

int shell_sort(item_t *array,int left,int right)
{
	int h;
	int i,j;
	item_t temp;

	for(h=1;h<=(right-left)/9;h=3*h+1)
		;

	for(;h>4;h/=3){
		for(i=left+h;i<=right;i++){
			copy_item(&temp,&array[i]);

			for(j=i-h;j>=left && compare_item(array[j],temp)>0;j-=h){
					copy_item(&array[j+h],&array[j]);
			}

			copy_item(&array[j+h],&temp);
		}
	}	
	h=3*h+1;
	
	return(h);
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;
	clock_t c1,c2;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	c1=clock();
	merge_sort(array,0,N-1);
	c2=clock();
	print_array(array,N);
	printf("mergesort time: %.5fs\n",(double)(c2-c1)/CLOCKS_PER_SEC);

	free(array);

	return(0);
}
