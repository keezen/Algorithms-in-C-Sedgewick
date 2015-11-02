/*
** This program generates N 30-byte strings of a specific format, and sort them using
** MSD radix sort. Then print out the number of bytes examined in the sorting process.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<assert.h>
#include"item.h"
#include"radix.h"

void print_array(item_t *array,int n_elements);
void msd_radixsort(item_t *array,int left,int right);
void do_msd_radixsort(item_t *array,int left,int right,int w);
void rand_item(item_t *x);
void generate_item(item_t *x);
void generate_init(void);

char ten_strings[10][4];
char fifty_strings[50][10];
char two_values[2];
int count_bytes=0;

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(item_t));
	int i,j;

	srand((unsigned)time(NULL));	
	generate_init();

	for(i=0;i<N;i++){
		generate_item(&array[i]);
	}
//	print_array(array,N);

	msd_radixsort(array,0,N-1);
//	print_array(array,N);
	printf("number of bytes examined: %d\n",count_bytes);

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

void msd_radixsort(item_t *array,int left,int right)
{
	do_msd_radixsort(array,left,right,0);
}

void do_msd_radixsort(item_t *array,int left,int right,int w)
{
	int n=right-left+1;
	item_t *aux;
	int count[R];
	int i;

	if(right-left+1<=1 || w>=bytesword){
		count_bytes+=0;
		return;
	}


	for(i=0;i<R;i++){
		count[i]=0;
	}

	for(i=left;i<=right;i++){
		count[digit(array[i],w)+1]++;
	}

	for(i=1;i<R;i++){
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

	count_bytes+=n;
}

void rand_item(item_t *x)
{
	int i;

	for(i=0;i<bytesword;i++){
		(*x)[i]=rand()%R;
	}
}

/*
** This key generator generates 30-byte strings made of four fields: a 4-byte field
** with one of a set of 10 given strings; a 10-byte field with one of a set of 50 given
** strings; a 1-byte field with one of two given characters; and a 15-byte field with 
** random left-justified strings of letters equally likely to be 4 through 15 characters
** long.
*/
void generate_item(item_t *x)
{
	int index,length;
	int i,j;

	index=rand()%10;
	for(i=0;i<4;i++){
		(*x)[i]=ten_strings[index][i];
	}

	index=rand()%50;
	for(i=4;i<14;i++){
		(*x)[i]=fifty_strings[index][i-4];
	}

	index=rand()%2;
	(*x)[14]=two_values[index];

	length=rand()%12+4;
	for(i=15;i<15+length;i++){
		(*x)[i]=rand()%26+1;
	}
	for(;i<bytesword;i++){
		(*x)[i]=0;
	}
}

void generate_init(void)
{
	FILE *input;
	int i,j;
	char buf[50]={0};

	
	input=fopen("radix_sort_bytes_examined_input.txt","r");
	assert(input!=NULL);

	for(i=0;i<10;i++){
		fscanf(input,"%s",buf);
		
		for(j=0;j<4 && buf[j]!=0;j++){
			if(isupper(buf[j])){
				ten_strings[i][j]=buf[j]-'A'+1;
				continue;
			}

			if(islower(buf[j])){
				ten_strings[i][j]=buf[j]-'a'+1;
				continue;
			}
		}

		for(;j<4;j++){
			ten_strings[i][j]=0;
		}
	}

	for(i=0;i<50;i++){
		fscanf(input,"%s",buf);

		for(j=0;j<10 && buf[j]!=0;j++){
			if(isupper(buf[j])){
				fifty_strings[i][j]=buf[j]-'A'+1;
				continue;
			}

			if(islower(buf[j])){
				fifty_strings[i][j]=buf[j]-'a'+1;
				continue;
			}
		}

		for(;j<10;j++){
			fifty_strings[i][j]=0;
		}
	}

	fclose(input);

	two_values[0]=1;
	two_values[1]=2;
}
