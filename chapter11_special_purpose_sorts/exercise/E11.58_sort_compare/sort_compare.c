#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"radix.h"
#include"item.h"

typedef void (*func_t)(item_t *array,int left,int right);


void print_array(item_t *array,int n_elements);

void quicksort(item_t *array,int left,int right);
int partition(item_t *array,int left,int right);

void lsd_radixsort(item_t *array,int left,int right);

void msd_radixsort(item_t *array,int left,int right);
void do_msd_radixsort(item_t *array,int left,int right,int w);

void heapsort(item_t *array,int left,int right);
void heapify_top_down(item_t *heap,int k,int n);


func_t sorts[4]={quicksort,lsd_radixsort,msd_radixsort,heapsort};


int main(int argc,char *argv[])
{
	int which=atoi(argv[1]);
	int N=atoi(argv[2]);
	item_t *array;
	int i;
	clock_t c1,c2;


	srand((unsigned)time(NULL));

	array=malloc(N*sizeof(*array));
	for(i=0;i<N;i++){
		array[i]=rand();
	}
//	print_array(array,N);

	c1=clock();
	sorts[which](array,0,N-1);
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
		putchar(' ');
	}
	putchar('\n');
}

void quicksort(item_t *array,int left,int right)
{
	int i;

	if(right-left+1 <= 1){
		return;
	}

	i=partition(array,left,right);
	quicksort(array,left,i-1);
	quicksort(array,i+1,right);
}

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

void lsd_radixsort(item_t *array,int left,int right)
{
	int i;
	int w;
	int n=right-left+1;
	int count[R+1];
	item_t *aux;

	if(right-left+1<=1){
		return;
	}


	aux=malloc(n*sizeof(*aux));

	for(w=bytesword-1;w>=0;w--){
		for(i=0;i<=R;i++){
			count[i]=0;
		}
	
		for(i=left;i<=right;i++){
			count[digit(array[i],w)+1]++;
		}
	
		for(i=1;i<=R;i++){
			count[i]+=count[i-1];
		}


		for(i=left;i<=right;i++){
			copy_item(&aux[count[digit(array[i],w)]++],&array[i]);
		}
	
		for(i=left;i<=right;i++){
			copy_item(&array[i],&aux[i-left]);	
		}
	}

	free(aux);
}

void msd_radixsort(item_t *array,int left,int right)
{
	do_msd_radixsort(array,left,right,0);
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

void heapsort(item_t *array,int left,int right)
{
	int n=right-left+1;
	item_t *pq=array+left-1;
	int i,k;

	for(k=n/2;k>=1;k--){
		heapify_top_down(pq,k,n);
	}
	
	for(i=n;i>1;i--){
		swap_item(&pq[1],&pq[i]);
		heapify_top_down(pq,1,i-1);
	}
}

void heapify_top_down(item_t *heap,int k,int n)
{
	int j;

	while(2*k<=n){
		j=2*k;
		if(j+1<=n && compare_item(heap[j+1],heap[j])>0){
			j++;
		}

		if(compare_item(heap[k],heap[j])>=0){
			break;
		}
		swap_item(&heap[k],&heap[j]);
		k=j;
	}
}
