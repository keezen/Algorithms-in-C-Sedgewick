/*
** This program reads a sequence of strings from the outer file, and then sorts 
** these strings by LSD radix sort on the first two characters. The sequence of
** strings is: now is the time for all good people to come the aid of their party.
*/
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"item.h"
#include"radix.h"

#define N_MAX 50

void print_array(item_t *array,int n_elements);
void lsd_radixsort(item_t *array,int left,int right);

int main(void)
{
	int N;
	item_t strings[N_MAX]={0};
	FILE *input;
	
	input=fopen("radix_sort_lsd_input.txt","r");
	assert(input!=NULL);
	for(N=0;fscanf(input,"%s",strings[N])==1;N++)
		;
	fclose(input);
	print_array(strings,N);

	lsd_radixsort(strings,0,N-1);
	print_array(strings,N);

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

	/*
	** LSD sort begins on the second byte, i.e., w==1.
	*/
	for(w=1;w>=0;w--){
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
