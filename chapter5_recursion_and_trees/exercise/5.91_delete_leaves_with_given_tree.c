#include<stdio.h>
#include<stdlib.h>
#include"tree.h"

link_t delete_leaves(link_t x,cont_t v)
{
	if(x==NULL)
		return(NULL);

	if(Left(x)==NULL && Right(x)==NULL && Cont(x)==v){
		free(x);
		return(NULL);
	}

	leftAdd(x,delete_leaves(Left(x),v));
	rightAdd(x,delete_leaves(Right(x),v));

	return(x);
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

	puts("original tree:");
	root=tournament(array,head,tail);
	treeShow(root);
	putchar('\n');

	puts("changed tree:");
	root=delete_leaves(root,'M');
	treeShow(root);	

	return(0);
}
