#include<stdlib.h>
#include<stdio.h>
#include"tree.h"

struct node{
        cont_t cont;
        link_t left,right;
};

link_t newNode(cont_t cont)
{
	link_t t=malloc(sizeof(*t));

	t->cont=cont;
	t->left = t->right = NULL;

	return(t);
}

link_t Left(link_t x)
{
	return(x->left);
}

link_t Right(link_t x)
{
	return(x->right);
}

cont_t Cont(link_t x)
{
	return(x->cont);
}

void leftAdd(link_t root,link_t left)
{
	root->left=left;
}

void rightAdd(link_t root,link_t right)
{
	root->right=right;
}

static void printNode(link_t x,int level)
{
	int i;

	for(i=0;i<level;i++)
		printf("  ");

	if(x==NULL){
		putchar('#');
		putchar('\n');
		return;
	}

	putchar(Cont(x));
	putchar('\n');
}


static void Show(link_t root,int level)
{
	if(root==NULL){
		printNode(root,level);
		return;
	}

	Show(Right(root),level+1);	

	printNode(root,level);

	Show(Left(root),level+1);
}

void treeShow(link_t t)
{
	int level=0;

	Show(t,0);
}
