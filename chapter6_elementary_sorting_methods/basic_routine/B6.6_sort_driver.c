/*
** This driver conducts basic array sorts. It uses two explicit
** interfaces: one for the functions associated with arrays, and
** the other for operations performed on generic items.
*/
#include<stdlib.h>
#include<time.h>
#include"item.h"
#include"array.h"

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	item_t *array=malloc(N*sizeof(*array));

	srand((unsigned)time(NULL));

	randinit_array(array,N);
	
	print_array(array,0,N-1);

	sort_array(array,0,N-1);

	print_array(array,0,N-1);

	return(0);
}
