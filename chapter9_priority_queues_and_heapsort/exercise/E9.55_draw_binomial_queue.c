/*
** This program can draw the binomial-tree representation of a binomial
** queeu, given the size N (just nodes connected by edges, no keys). The
** binomail tree this programs draws may be a little weird to understand.
** This is the method to read it: (1) the tree node is represented by a
** star '*'; (2) the child node is one more tab than the parent node from
** the left, and is located below the parent; (3) the tree spreads horizontally
** from left to right, that is, it is the ordinary tree rotated a right angle
** counterclockwise. So you can adopt the rules above to translate the tree
** into a normal one.
*/
#include<stdio.h>

void draw_binomial_queue(int n_elements);
void print_binomial_tree(int power);
void do_print_binomial_tree(int power,int level);

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);

	draw_binomial_queue(N);

	return(0);
}

void draw_binomial_queue(int n_elements)
{
	int n=n_elements;
	int i;

	for(i=0;n!=0;i++,n/=2){
		printf("2^%d-heap:\n",i);

		if(n%2==1){
			print_binomial_tree(i);
		}else{
			printf("#\n");
		}

		putchar('\n');
	}
}

void print_binomial_tree(int power)
{
	do_print_binomial_tree(power,1);
}

void do_print_binomial_tree(int power,int level)
{
	int i;

	if(power<0){
		return;
	}

	for(i=1;i<level;i++){
		putchar('\t');
	}

	printf("*\n");

	for(i=power-1;i>=0;i--){
		do_print_binomial_tree(i,level+1);
	}
}
