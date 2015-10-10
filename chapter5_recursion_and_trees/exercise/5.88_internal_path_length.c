#include<stdio.h>
#include"tree.h"

int path_length(link_t root,int level)
{
	link_t l,r;
	
	if(root==NULL)
		return(0);

	l=Left(root);
	r=Right(root);	

	return(path_length(l,level+1)+path_length(r,level+1)+level);
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

	printf("internal path length:%d\n",path_length(root,0));

	return(0);
}
