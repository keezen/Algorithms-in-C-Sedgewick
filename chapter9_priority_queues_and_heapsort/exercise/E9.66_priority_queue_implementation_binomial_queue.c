#include<stdlib.h>
#include<stdio.h>
#include"pqueue.h"
#include"item.h"

#define BQ_MAX_SIZE 100

typedef struct PQUEUE_NODE* pqueue_link_t;
struct PQUEUE_NODE{
	item_t item;
	pqueue_link_t left;
	pqueue_link_t right;
};

static pqueue_link_t *bq;
static int bq_size;

static pqueue_link_t pair_2_power_heap(pqueue_link_t roota,pqueue_link_t rootb);
static void bqueue_join(pqueue_link_t *bq1,pqueue_link_t *bq2,int max_size);

void pqueue_init(int Nmax)
{
	int i;

	bq=malloc(BQ_MAX_SIZE*sizeof(*bq));
	bq_size=0;

	for(i=0;i<BQ_MAX_SIZE;i++){
		bq[i]=NULL;
	}
}

int pqueue_empty(void)
{
	return(bq_size==0);
}

void pqueue_insert(item_t item)
{
	pqueue_link_t new,c;
	int i;

	new=malloc(sizeof(*new));
	copy_item(&new->item,&item);
	new->left=NULL;
	new->right=NULL;

	for(c=new,i=0;i <= bq_size;i++){
		if(bq[i]==NULL){
			bq[i]=c;
			break;
		}

		c=pair_2_power_heap(c,bq[i]);
		bq[i]=NULL;
	}

	if(i==bq_size){
		bq_size++;
	}
}

item_t pqueue_del_max(void)
{
	int i,max;
	item_t max_item;
	pqueue_link_t temp_bq[BQ_MAX_SIZE];
	pqueue_link_t x;

	for(max=-1,i=0;i < bq_size;i++){
		if(bq[i]!=NULL){
			if(max==-1 || compare_item(bq[i]->item,bq[max]->item)>0){
				max=i;
			}
		}
	}
	copy_item(&max_item,&bq[max]->item);

	for(i=0;i <= bq_size;i++){
		temp_bq[i]=NULL;
	}

	x=bq[max]->left;
	for(i=max-1;i>=0;i--){
		temp_bq[i]=x;
		x=x->right;
		temp_bq[i]->right=NULL;
	}

	free(bq[max]);
	bq[max]=NULL;
	bqueue_join(bq,temp_bq,bq_size);

	if(bq[bq_size-1]==NULL){
		bq_size--;
	}

	return(max_item);
}

static pqueue_link_t pair_2_power_heap(pqueue_link_t roota,pqueue_link_t rootb)
{
	if(compare_item(roota->item,rootb->item)>0){
		rootb->right=roota->left;
		roota->left=rootb;

		return(roota);
	}else{
		roota->right=rootb->left;
		rootb->left=roota;

		return(rootb);
	}
}

#define test(A,B,C) (1*(A)+2*(B)+4*(C))
static void bqueue_join(pqueue_link_t *bq1,pqueue_link_t *bq2,int max_size)
{
	int i;
	pqueue_link_t c;

	for(c=NULL,i=0;i<=max_size;i++){
		switch(test(bq1[i]!=NULL,bq2[i]!=NULL,c!=NULL)){
			case 0:
			case 1:
				break;
			case 2:
				bq1[i]=bq2[i];
				break;
			case 3:
				c=pair_2_power_heap(bq1[i],bq2[i]);
				bq1[i]=NULL;
				break;
			case 4:
				bq1[i]=c;
				c=NULL;
				break;
			case 5:
				c=pair_2_power_heap(bq1[i],c);
				bq1[i]=NULL;
				break;
			case 6:
			case 7:
				c=pair_2_power_heap(bq2[i],c);
				break;
		}
	}
}
