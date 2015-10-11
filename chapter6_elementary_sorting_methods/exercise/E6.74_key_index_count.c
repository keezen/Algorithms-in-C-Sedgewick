#include<stdio.h>

#define N 11
#define M 5

void key_index_count(int array[],int left,int right);
void print_array_char(char array[],int n_elements);

void key_index_count(int array[],int left,int right)
{
	int count[M];
	int b[N];
	int i;

	for(i=0;i<M;i++){
		count[i]=0;
	}

	for(i=left;i<=right;i++){
		count[array[i]+1]++;
	}

	for(i=1;i<M;i++){
		count[i]+=count[i-1];	
	}

	for(i=left;i<=right;i++){
		b[count[array[i]]++]=array[i];
	}

	for(i=left;i<=right;i++){
		array[i]=b[i-left];
	}
}

void print_array_char(char array[],int n_elements)
{
	int i;

	for(i=0;i<n_elements;i++){
		printf("%c ",array[i]);
	}
	putchar('\n');
}

/*
** Using key-indexed counting sorts the char file ABRACADABRA.
*/
int main(void)
{
	char string[N]="ABRACADABRA";
	char maps[M]="ABCDR";
	int code;
	int array[N];
	int i;

	print_array_char(string,N);

	/*
	** Translate the char string into an integer array, according
	** to the maps, in which 0 is A, 1 is B, 2 is C, 3 is D, and 4
	** is R.
	*/
	for(i=0;i<N;i++){
		for(code=0;code<M && string[i]!=maps[code];code++)
			;

		array[i]=code;
	}

	/*
	** Key-indexed counting sorts the "coded" array.
	*/
	key_index_count(array,0,N-1);

	/*
	** Translate the sorted integer array back to the string.
	*/
	for(i=0;i<N;i++){
		string[i]=maps[array[i]];
	}

	print_array_char(string,N);

	return(0);
}
