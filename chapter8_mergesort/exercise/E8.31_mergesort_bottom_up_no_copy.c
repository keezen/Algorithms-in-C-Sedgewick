#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

void merge_ab(item_t *c,item_t *a,int m,item_t *b,int n);
void merge_sort(item_t *array,int left,int right);
void print_array(item_t *array,int n_elements);
int min_int(int a,int b);

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		print_item(array[i]);
		putchar(' ');
	}
	putchar('\n');
}

void merge_ab(item_t *c,item_t *a,int m,item_t *b,int n)
{
	int i,j,k;

	for(i=0,j=0,k=0;k<m+n;k++){
		if(i==m){
			c[k]=b[j++];
			continue;
		}
		if(j==n){
			c[k]=a[i++];
			continue;	
		}

		if(compare_item(a[i],b[j])<0){
			c[k]=a[i++];
		}else{
			c[k]=b[j++];
		}
	}
}

/*
** Bottom-up mergesort with no apparent array copy. To avoid apparent
** copy, we use an auxiliary array aux. Original array and aux array
** take turns to be the resultant array of two-way merge. So the copy
** is virtually completed in the process of merge_ab. However we still
** use an apparent copy loop in the end, but it would't take up too
** much cost.
*/
void merge_sort(item_t *array,int left,int right)
{
	int n=right-left+1;
	int i,m,flag;
	item_t *aux;

	if(right-left+1<=1){
		return;
	}

	aux=malloc(n*sizeof(*aux));

	flag=1;
	for(m=1;m<=right-left;m*=2){
		for(i=left;i<=right-m;i+=2*m){
			if(flag==1){
				merge_ab(aux+i-left,array+i,m,array+i+m,min_int(m,right-m-i+1));
			}else{
				merge_ab(array+i,aux+i-left,m,aux+i+m-left,min_int(m,right-m-i+1));
			}
		}

		flag=(flag==0)?1:0;
	}

	if(flag==0){
		for(i=left;i<=right;i++){
			array[i]=aux[i-left];
		}
	}

	free(aux);
}

int min_int(int a,int b)
{
	if(a<b){
		return(a);
	}
	
	return(b);
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));
	int i;

	srand((unsigned)time(NULL));

	for(i=0;i<N;i++){
		array[i]=rand()%N;
	}
	print_array(array,N);

	merge_sort(array,0,N-1);
	print_array(array,N);

	free(array);

	return(0);
}
