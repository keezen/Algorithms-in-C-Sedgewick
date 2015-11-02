/*
** This program generates N generated 80-byte keys with R=2, and sorts them with 
** two different methods: MSD radix sort and LSD radix sort. 
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"radix.h"

/* The macro LSD is a flag indicating which method is to be used. */
#define LSD 1

void print_array(item_t *array,int n_elements);
void radix_sort(item_t *array,int left,int right);
void lsd_radixsort(item_t *array,int left,int right);
void do_msd_radixsort(item_t *array,int left,int right,int w);
void rand_item(item_t *x);
void generate_item(item_t *x);

item_t sequence;

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(item_t));
	int i;
	clock_t c1,c2;

	srand((unsigned)time(NULL));	

	rand_item(&sequence);
	for(i=0;i<N;i++){
		generate_item(&array[i]);
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
	#if LSD
	lsd_radixsort(array,left,right);
	#else
	do_msd_radixsort(array,left,right,0);
	#endif
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

/*
** The generate_item function generates a 80-byte key by shuffling a random 80-byte
** sequence.
*/
void generate_item(item_t *x)
{
	int i;
	int j;
	char t;

	for(i=0;i<bytesword;i++){
		(*x)[i]=sequence[i];
	}

	for(i=bytesword-1;i>0;i--){
		j=rand()%i;

		t=(*x)[i];
		(*x)[i]=(*x)[j];
		(*x)[j]=t;
	}
}
