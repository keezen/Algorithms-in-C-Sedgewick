#include<stdlib.h>
#include"tree.h"

link_t newNode(item_t item)
{
	link_t t=malloc(sizeof(*t));

	t->item=item;
	t->left = t->right = NULL;

	return(t);
}

