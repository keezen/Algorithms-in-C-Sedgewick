#include<stdio.h>
#include"tree.h"

void visit(link_t x)
{
	printf("%c\t",Cont(x));
}

void traverse(link_t root,void (*visit)(link_t))
{
	link_t x;
	
	queueInit(100);
	queuePut(root);

	putchar('\t');
	queueItemPrint();
	putchar('\n');	

	while(!queueEmpty()){
		x=queueGet();
		visit(x);
		if(Left(x) != NULL)
			queuePut(Left(x));
		if(Right(x) !=NULL)
			queuePut(Right(x));

		queueItemPrint();
		putchar('\n');
	};
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

	return(0);
}
