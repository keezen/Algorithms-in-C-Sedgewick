#include<stdio.h>
#include"tree.h"
#include"cont.h"

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

link_t tournament(cont_t array[],int head,int tail)
{
	cont_t max;
	link_t root,l,r;
	int mid=(head+tail)/2;

	if(head==tail){
		root=newNode(array[head]);
		return(root);
	}

	l=tournament(array,head,mid);
	r=tournament(array,mid+1,tail);

	max=(Cont(l)>Cont(r))?(Cont(l)):(Cont(r));

	root=newNode(max);
	leftAdd(root,l);
	rightAdd(root,r);

	return(root);
}

int main(void)
{
	link_t root;
	cont_t array[6]="AMPLE";
	int head=0,tail=4;

	root=tournament(array,head,tail);
	treeShow(root,0);

	return(0);
}
