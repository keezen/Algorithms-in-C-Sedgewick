#include<stdio.h>
#include"tree.h"

int count(link_t root)
{
	if(root==NULL)
		return(0);
	return(count(Left(root)) + count(Right(root)) + 1);
}

int height(link_t root)
{
	int height_l,height_r;

	if(root==NULL)
		return(-1);

	height_l=height(Left(root));
	height_r=height(Right(root));

	if(height_l > height_r)
		return(height_l+1);

	return(height_r+1);
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

	printf("number of internal nodes:%d\n",count(root));
	printf("height of the tree:%d\n",height(root));

	return(0);
}
