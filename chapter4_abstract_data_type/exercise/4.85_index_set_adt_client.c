#include<stdio.h>
#include"set.h"

#define M 10

int main(void)
{
	set_t s1,s2,s3,s4,s5,s6;

	s1=setCrea(M);
	setInsert(s1,0);
	setInsert(s1,1);
	printf("s1:");
	setPrint(s1);
	putchar('\n');

	s2=setCrea(M);
	setInsert(s2,9);
	setInsert(s2,0);
	printf("s2:");
	setPrint(s2);
	putchar('\n');

	s3=setUnion(s1,s2);
	printf("s3:");
	setPrint(s3);
	putchar('\n');

	s4=setInter(s1,s2);
	printf("s4:");
	setPrint(s4);
	putchar('\n');	

	s5=setCompl(s4);
	printf("s5:");
	setPrint(s5);
	putchar('\n');

	s6=setDiff(s3,s5);
	printf("s6:");
	setPrint(s6);
	putchar('\n');

	return(0);
}
