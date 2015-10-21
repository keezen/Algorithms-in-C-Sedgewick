/*
** The implementation for priority queue interface that supports construct
** and delete the maximum, using tournaments (see B5.19, it will provide you
** with the basis for construct).
*/
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"pqueue.h"
#include"item.h"

typedef struct PQUEUE_NODE* pqueue_link_t;
struct PQUEUE_NODE{
	item_t item;
	pqueue_link_t left;
	pqueue_link_t right;
};

static pqueue_link_t do_pqueue_construct(item_t *array,int left,int right);
static void do_pqueue_print(pqueue_link_t r);
static pqueue_link_t do_pqueue_del_max(pqueue_link_t r);

static pqueue_link_t root;

void pqueue_init(int Nmax)
{
	root=NULL;
}

int pqueue_empty(void)
{
	return(root==NULL);
}

void pqueue_construct(item_t *array,int left,int right)
{
	root=do_pqueue_construct(array,left,right);
}

item_t pqueue_del_max(void)
{
	item_t max_item;

	assert(!pqueue_empty());

	copy_item(&max_item,&root->item);
	root=do_pqueue_del_max(root);

	return(max_item);
}

void pqueue_print(void)
{
	do_pqueue_print(root);
	putchar('\n');
}

static pqueue_link_t do_pqueue_construct(item_t *array,int left,int right)
{
	pqueue_link_t r;
	int middle=(left+right)/2;
	item_t max_item;

	r=malloc(sizeof(*r));
	r->left=NULL;
	r->right=NULL;

	if(right==left){
		r->item=array[left];
	
		return(r);
	}

	r->left=do_pqueue_construct(array,left,middle);
	r->right=do_pqueue_construct(array,middle+1,right);
	
	copy_item(&max_item,&r->left->item);
	if(compare_item(r->right->item,max_item)>0){
		copy_item(&max_item,&r->right->item);
	}
	copy_item(&r->item,&max_item);

	return(r);
}

static void do_pqueue_print(pqueue_link_t r)
{
	if(r->left==NULL && r->right==NULL){
		print_item(r->item);
		putchar(' ');
	
		return;
	}

	do_pqueue_print(r->left);
	do_pqueue_print(r->right);
}

static pqueue_link_t do_pqueue_del_max(pqueue_link_t r)
{
	item_t max_item;
	pqueue_link_t t;

	if(r->left==NULL && r->right==NULL){
		free(r);
		return(NULL);
	}

	if(compare_item(r->left->item,r->item)==0){
		r->left=do_pqueue_del_max(r->left);

		if(r->left==NULL){
			t=r->right;
			free(r);
			return(t);
		}
	}else{
		r->right=do_pqueue_del_max(r->right);

		if(r->right==NULL){
			t=r->left;
			free(r);
			return(t);
		}
	}

	copy_item(&max_item,&r->left->item);
	if(compare_item(r->right->item,max_item)>0){
		copy_item(&max_item,&r->right->item);
	}
	copy_item(&r->item,&max_item);

	return(r);
}
