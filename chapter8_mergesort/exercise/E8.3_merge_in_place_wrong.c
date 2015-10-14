#include<stdio.h>
#include"item.h"

#define N 12

void merge_ab(item_t *c,item_t *a,int m,item_t *b,int n);
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

int main(void)
{
	item_t a[N]="AEQSUYEINOST";

	print_array(a,N);

	merge_ab(a,a,N/2,a+N/2,N-N/2);
	print_array(a,N);

	return(0);
}
