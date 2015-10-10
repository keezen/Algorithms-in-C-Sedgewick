#include<stdio.h>
#include"tree.h"

void visit(link_t x)
{
	printf("%c ",x->item);
}

void traverse(link_t root,void (*visit)(link_t))
{
	if(root==NULL)
		return;

	visit(root);
	traverse(root->left,visit);
	traverse(root->right,visit);
}

int main(void)
{
	link_t root;

	root=newNode('E');

	root->left=newNode('D');
	root->right=newNode('H');

	root->left->left=newNode('B');
	root->right->left=newNode('F');
	
	root->left->left->left=newNode('A');
	root->left->left->right=newNode('C');
	root->right->left->right=newNode('G');

	traverse(root,visit);
	putchar('\n');

	return(0);
}
