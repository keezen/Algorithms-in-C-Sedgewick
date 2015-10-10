#include<stdio.h>
#include"tree.h"

void visit(link_t x)
{
	printf("%c ",Cont(x));
}

void traverse(link_t root,void (*visit)(link_t))
{
	link_t current;
	
	stackInit(100);
	for(current=root;current!=NULL;current=Left(current))
		stackPush(current);

	while(current==NULL && !stackEmpty()){
		current=stackPop();

		visit(current);

		for(current=Right(current);current!=NULL;current=Left(current))
			stackPush(current);	
	}
}

int main(void)
{
	link_t root;

	root=newNode('E');

	leftAdd(root,newNode('D'));
	rightAdd(root,newNode('H'));

	leftAdd(Left(root),newNode('B'));
	leftAdd(Right(root),newNode('F'));
	
	leftAdd(Left(Left(root)),newNode('A'));
	rightAdd(Left(Left(root)),newNode('C'));
	rightAdd(Left(Right(root)),newNode('G'));

	traverse(root,visit);
	putchar('\n');

	return(0);
}
