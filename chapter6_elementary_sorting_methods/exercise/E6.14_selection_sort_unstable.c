#include<stdio.h>

typedef struct{
	char name[20];
	int number;
} item_t;

int compare_int(void *a,void *b);
int compare_string(void *a,void *b);
void swap(void *a,void *b);
void selection_sort(item_t *array,int left,int right,int (*compare)(void *a,void *b));
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

void selection_sort(item_t *array,int left,int right,int (*compare)(void *a,void *b))
{
	int i,j;
	int min;

	for(i=left;i<right;i++){
		min=i;

		for(j=i+1;j<=right;j++){
			if(compare(&array[j],&array[min]) < 0){
				min=j;
			} 
		}

		swap(&array[i],&array[min]);
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

	selection_sort(students,0,9,compare_string);
	print_array(students,10);
	putchar('\n');	

	selection_sort(students,0,9,compare_int);
	print_array(students,10);
	putchar('\n');

	return(0);
}
