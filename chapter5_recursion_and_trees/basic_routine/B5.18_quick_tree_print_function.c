#include<stdio.h>
#include"tree.h"

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

void printNode(link_t x,int level)
{
	int i;

	for(i=0;i<level;i++)
		printf("  ");

	if(x==NULL){
		putchar('*');
		putchar('\n');
		return;
	}

	putchar(Cont(x));
	putchar('\n');
}

void treeShow(link_t root,int level)
{
	if(root==NULL){
		printNode(root,level);
		return;
	}

	treeShow(Right(root),level+1);	

	printNode(root,level);

	treeShow(Left(root),level+1);
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

	treeShow(root,0);
	
	return(0);
}
