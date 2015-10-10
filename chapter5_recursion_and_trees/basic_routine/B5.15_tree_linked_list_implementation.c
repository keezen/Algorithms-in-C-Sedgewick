#include<stdlib.h>
#include"tree.h"

link_t newNode(cont_t cont)
{
	link_t t=malloc(sizeof(*t));

	t->cont=cont;
	t->left = t->right = NULL;

	return(t);
}

