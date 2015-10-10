#include<stdlib.h>
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
