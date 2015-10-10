#include<stdio.h>
#include"tree.h"

int count_nodes(link_t root)
{
	link_t l,r;
	
	if(root==NULL)
		return(1);

	l=Left(root);
	r=Right(root);	

	return(count_nodes(l)+count_nodes(r)+1);
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

	printf("number of leaves:%d\n",count_nodes(root));

	return(0);
}
