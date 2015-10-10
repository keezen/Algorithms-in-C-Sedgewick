#include<stdio.h>
#include"tree.h"

void visit(link_t x)
{
	if(x==NULL)
		return;
	
	printf("%c ",x->cont);
}

void traverse(link_t root,void (*visit)(link_t))
{
	link_t x;
	int i;
	
	stackInit(100);
	stackPush(root);

	while(!stackEmpty()){
		x=stackPop();
		visit(x);
		if(x->right != NULL)
			stackPush(x->right);
		if(x->left !=NULL)
			stackPush(x->left);
	};
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
