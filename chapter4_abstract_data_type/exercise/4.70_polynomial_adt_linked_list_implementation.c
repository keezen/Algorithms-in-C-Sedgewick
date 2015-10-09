#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include"poly.h"

typedef struct node* link_t;
struct node{
	int exp;
	int coef;
	link_t next;	
};
struct poly{
	link_t head;
	int degr;
};

poly_t polyTerm(int coef,int exp)
{
	poly_t p=malloc(sizeof(*p));
	link_t x=malloc(sizeof(*x));
	
	x->coef=coef;
	x->exp=exp;
	x->next=NULL;

	p->head=x;
	p->degr=exp+1;
	
	return(p);
}	

static void mergeNode(poly_t p,link_t t)
{
	link_t x;

	if(p->head == NULL){
		p->head=t;
		return;
	}

	if(p->head->exp > t->exp){
		t->next = p->head;
		p->head = t;	
		return;	
	} 

	for(x=p->head;x->next != NULL && x->next->exp < t->exp;x=x->next)
		;

	if(x->next==NULL || x->next->exp > t->exp){	
		t->next = x->next;
		x->next = t;
		return;	
	}

	if(x->next->exp == t->exp){
		x->next->coef += t->coef;
		free(t);
		return;
	}

}

poly_t polyAdd(poly_t p1,poly_t p2)
{
	poly_t p=malloc(sizeof(*p));
	link_t x,t;
	
	p->degr = (p1->degr > p2->degr)?(p1->degr):(p2->degr);
	
	for(x=p1->head;x!=NULL;x=x->next){
		t=malloc(sizeof(*t));
		t->exp = x->exp;
		t->coef = x->coef;
		t->next = NULL;

		mergeNode(p,t);
	}
	for(x=p2->head;x!=NULL;x=x->next){
		t=malloc(sizeof(*t));
		t->exp = x->exp;
		t->coef = x->coef;
		t->next = NULL;
		
		mergeNode(p,t);
	}

	return(p);
}

poly_t polyMult(poly_t p1,poly_t p2)
{
	poly_t p=malloc(sizeof(*p));
	link_t x,y,t;

	p->degr = p1->degr + p2->degr -1;

	for(x=p1->head;x!=NULL;x=x->next)
		for(y=p2->head;y!=NULL;y=y->next){
			t=malloc(sizeof(*t));
			t->exp = x->exp + y->exp;
			t->coef = x->coef * y->coef;
			t->next = NULL;

			mergeNode(p,t);
		}
	
	return(p);
}

double polyEval(poly_t p,double x)
{
	link_t t;
	double y;

	for(y=0,t=p->head;t!=NULL;t=t->next)
		y += t->coef * pow(x,t->exp);
	
	return(y);
}

void polyShow(poly_t p)
{
	link_t x;
	for(x=p->head;x!=NULL;x=x->next)
		printf("%dx^%d ",x->coef,x->exp);
}
