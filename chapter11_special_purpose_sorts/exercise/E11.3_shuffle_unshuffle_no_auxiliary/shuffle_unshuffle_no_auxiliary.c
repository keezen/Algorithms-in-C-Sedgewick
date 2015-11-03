/*
** This program implements perfect shuffle and perfect unshuffle functions without
** using an auxiliary array.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"item.h"

void print_array(item_t *array,int n_elements);
void shuffle(item_t *array,int left,int right);
void unshuffle(item_t *array,int left,int right);


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

	shuffle(array,0,N-1);
	print_array(array,N);

	unshuffle(array,0,N-1);
	print_array(array,N);

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

/*
** This implementation of shuffle operation does not use an auxiliary array. But
** it uses a brute force method, which is not so elegant. This method uses the same idea
** as shuffling a deck: we divide the deck into two halves, and take one top card from
** each half every time, and add them to the result card heap. In this implementation,
** we main the result heap form array[left] to array[i-1], the first half from array[i]
** to array[j-1], and the second half from array[j] to array[right]. Every time we take
** an element from one of the two halves into position array[i], increment i,then adjust 
** the array to maintain the property above. When we reach the right end, the whole array
** will be shuffled.
*/
void shuffle(item_t *array,int left,int right)
{
	int i,j,k;
	int middle=(left+right)/2;
	item_t t;

	if(right-left+1<=2){
		return;
	}

	for(j=middle+1,i=left;i<=right;i++){
		if((i-left)%2==0){
			continue;
		}
		if((i-left)%2==1){
			copy_item(&t,&array[j]);
			
			for(k=j;k>i;k--){
				copy_item(&array[k],&array[k-1]);
			}
	
			copy_item(&array[i],&t);
			j++;
		}
	}
}

/*
** This implementation of unshuffle operation does not use an auxiliary array, by the brute force
** method. This method maintains the following property: the first resultant half is between
** array[left] and array[m], the second resultant half is from array[m+1] and array[i-1], and the
** original shuffled part is from array[i] and array[right].
*/
void unshuffle(item_t *array,int left,int right)
{
	int i,j,m;
	item_t t;

	if(right-left+1<=2){
		return;
	}

	for(m=0,i=left+2;i<=right;i++){
		if((i-left)%2==1){
			continue;
		}
		if((i-left)%2==0){
			copy_item(&t,&array[i]);

			for(j=i;j>m+1;j--){
				copy_item(&array[j],&array[j-1]);
			}

			copy_item(&array[j],&t);
			m++;
		}
	}
}
