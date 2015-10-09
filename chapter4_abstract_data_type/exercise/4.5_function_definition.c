#include"item.h"

item_t lg(int N);

int main(void)
{
	int i,N;

	for(N=10,i=1;i<=6;N*=10,i++){
		ITEMshow(N);
		putchar(' ');
		ITEMshow(lg(N));
		putchar(' ');
		ITEMshow(N*lg(N));
		putchar('\n');
	}

	return(0);
}

item_t lg(int N)
{
	item_t count;

	for(count=0;N>0;N/=2,count++);
	return(count);
}
