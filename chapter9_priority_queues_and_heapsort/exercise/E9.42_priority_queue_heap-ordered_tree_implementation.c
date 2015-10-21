/*
** This implementation for the priority queue interface uses complete heap-ordered
** trees represented with explicit nodes and links. In the two heapify functions,
** we just exchange information fields in nodes rather than the nodes themselves.
*/
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include"pqueue.h"
#include"item.h"

typedef struct PQUEUE_NODE* pqueue_link_t;
struct PQUEUE_NODE{
	item_t item;
	pqueue_link_t parent;
	pqueue_link_t left;
	pqueue_link_t right;
};

static void do_pqueue_print(pqueue_link_t r);
static void heapify_bottom_up(pqueue_link_t x);
static void heapify_top_down(pqueue_link_t x);

static pqueue_link_t root;
static pqueue_link_t end;

void pqueue_init(int Nmax)
{
	root=end=NULL;
}

int pqueue_empty(void)
{
	return(root==NULL);
}

void pqueue_insert(item_t item)
{
	pqueue_link_t new;
	pqueue_link_t x;

	new=malloc(sizeof(*new));
	copy_item(&(new->item),&item);
	new->parent=new;
	new->left=NULL;
	new->right=NULL;

	if(root==NULL){
		root=end=new;
		return;
	}

	if(end==root){
		end->left=new;
		new->parent=root;
		end=new;

		heapify_bottom_up(end);

		return;
	}

	if(end->parent->left==end){
		end->parent->right=new;
		new->parent=end->parent;
		end=new;

		heapify_bottom_up(end);

		return;
	}

	if(end->parent->right==end){
		for(x=end;x->parent->right==x;x=x->parent)
			;
		if(x!=root){
			x=x->parent->right;
		}
		for(;x->left!=NULL;x=x->left)
			;
	
		x->left=new;
		new->parent=x;
		end=new;

		heapify_bottom_up(end);
	}
}

item_t pqueue_del_max(void)
{
	item_t max_item;
	pqueue_link_t t,x;

	assert(!pqueue_empty());

	copy_item(&max_item,&(root->item));
	copy_item(&(root->item),&(end->item));

	if(end==root){
		free(root);
		root=end=NULL;

		return(max_item);
	}

	if(end->parent->right==end){
		t=end;
		end->parent->right=NULL;
		end=end->parent->left;
		free(t);

		heapify_top_down(root);
		return(max_item);
	}

	if(end->parent->left==end){
		t=end;
		end->parent->left=NULL;
		x=end->parent;
		free(t);

		for(;x->parent->left==x;x=x->parent)
			;
		if(x!=root){
			x=x->parent->left;
		}
		for(;x->right!=NULL;x=x->right)
			;
		end=x;

		heapify_top_down(root);
		return(max_item);
	}
}

void pqueue_print(void)
{
	do_pqueue_print(root);
	putchar('\n');
}

static void do_pqueue_print(pqueue_link_t r)
{
	if(r==NULL){
		return;
	}

	print_item(r->item);
	putchar(' ');

	do_pqueue_print(r->left);
	do_pqueue_print(r->right);
}

static void heapify_bottom_up(pqueue_link_t x)
{
	pqueue_link_t t;

	for(t=x;t!=root;t=t->parent){
		if(compare_item(t->item,t->parent->item)<=0){
			break;
		}
		
		swap_item(&(t->item),&(t->parent->item));
	}
}

static void heapify_top_down(pqueue_link_t x)
{
	pqueue_link_t current,next;

	current=x;
	while(current->left!=NULL || current->right!=NULL){
		next=current->left;
		if(current->right!=NULL && compare_item(current->right->item,next->item)>0){
			next=current->right;
		}

		if(compare_item(current->item,next->item)>=0){
			break;
		}
		swap_item(&(current->item),&(next->item));
		current=next;
	}
}
