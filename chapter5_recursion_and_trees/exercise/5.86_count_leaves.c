#include<stdio.h>
#include"tree.h"

int count_leave(link_t root)
{
	link_t l,r;
	
	if(root==NULL)
		return(0);

	l=Left(root);
	r=Right(root);
	if(l==NULL && r==NULL)
		return(1);
	
	return(count_leave(l)+count_leave(r));
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

	treeShow(root);

	printf("number of leaves:%d\n",count_leave(root));

	return(0);
}
