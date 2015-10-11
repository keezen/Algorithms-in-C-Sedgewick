#include<stdio.h>

typedef struct{
	char name[20];
	int number;
} item_t;

int compare_int(void *a,void *b);
int compare_string(void *a,void *b);
void swap(void *a,void *b);
void shell_sort(item_t *array,int left,int right,int (*compare)(void *a,void *b));
void print_array(item_t *array,int n_elements);

int compare_int(void *a,void *b)
{
	return(((item_t *)a)->number - ((item_t *)b)->number);
}

int compare_string(void *a,void *b)
{
	return(strcmp(((item_t *)a)->name,((item_t *)b)->name));
}

void swap(void *a,void *b)
{
	char *pa=a;
	char *pb=b;
	char t;
	int i;

	for(i=0;i<sizeof(item_t);i++){
		t=pa[i];
		pa[i]=pb[i];
		pb[i]=t;
	}
}

void shell_sort(item_t *array,int left,int right,int (*compare)(void *a,void *b))
{
	int h;
	int i,j;
	item_t temp;

	for(h=1;h<=(right-left)/9;h=3*h+1)
		;

	for(;h>0;h/=3){
		for(i=left+h;i<=right;i++){
			temp=array[i];

			for(j=i-h;j>=left && compare(&array[j],&temp)>0;j-=h){
					array[j+h]=array[j];
			}

			array[j+h]=temp;
		}
	}
}

void print_array(item_t *array,int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		printf("%-20s %d\n",array[i].name,array[i].number);
	}
}

int main(void)
{
	item_t students[10]={
		{"Wilson",3},
		{"White",3},
		{"Washington",2},
		{"Thompson",4},
		{"Smith",1},
		{"Jones",4},
		{"Jackson",2},
		{"Brown",4},
		{"Black",2},
		{"Adams",1}
	};

	print_array(students,10);
	putchar('\n');

	shell_sort(students,0,9,compare_string);
	print_array(students,10);
	putchar('\n');	

	shell_sort(students,0,9,compare_int);
	print_array(students,10);
	putchar('\n');

	return(0);
}
