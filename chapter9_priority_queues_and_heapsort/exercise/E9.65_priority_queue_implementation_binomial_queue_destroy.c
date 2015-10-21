/*
** The implementation that has taken accout of memory leaks. The pqueue_destroy
** function is added to destroy the memory allocated for the priority queue data
** type pqueue_t pq. We also modify the pqueue_join function so that the priority
** queue data types in the parameters are destroyed, and a new one is created and
** returned as the result.
*/
#include<stdlib.h>
#include<stdio.h>
#include"pqueue_full.h"
#include"item.h"

#define BQ_MAX_SIZE 100

struct PQUEUE_NODE{
	item_t item;
	pqueue_link_t left;
	pqueue_link_t right;
};
struct PQUEUE{
	pqueue_link_t *bq;
};

static pqueue_link_t pair_2_power_heap(pqueue_link_t roota,pqueue_link_t rootb);
static void print_2_power_heap(pqueue_link_t root);
static void bqueue_join(pqueue_link_t *bq1,pqueue_link_t *bq2);

pqueue_t pqueue_init(int Nmax)
{
	pqueue_t pq;
	int i;

	pq=malloc(sizeof(*pq));
	pq->bq=malloc(BQ_MAX_SIZE*sizeof(pqueue_link_t));

	for(i=0;i<BQ_MAX_SIZE;i++){
		(pq->bq)[i]=NULL;
	}

	return(pq);
}

/*
** The pqueue_destroy function only destroys the priority queue data type pqueue_t
** created by pqueue_init, not the nodes pqueue_link_t. By the way, the node memory
** is created by pqueue_insert function, and destroyed by pqueue_del_max function.
*/
void pqueue_destroy(pqueue_t pq)
{
	free(pq->bq);
	free(pq);
}

int pqueue_empty(pqueue_t pq)
{
	int i;

	for(i=0;i<BQ_MAX_SIZE;i++){
		if((pq->bq)[i]!=NULL){
			break;
		}
	}

	return(i==BQ_MAX_SIZE);
}

pqueue_link_t pqueue_insert(pqueue_t pq,item_t item)
{
	pqueue_link_t new;
	pqueue_link_t temp_bq[BQ_MAX_SIZE];
	int i;

	new=malloc(sizeof(*new));
	copy_item(&new->item,&item);
	new->left=NULL;
	new->right=NULL;

	temp_bq[0]=new;
	for(i=1;i<BQ_MAX_SIZE;i++){
		temp_bq[i]=NULL;
	}

	bqueue_join(pq->bq,temp_bq);

	return(new);
}

item_t pqueue_del_max(pqueue_t pq)
{
	int i,max;
	item_t max_item;
	pqueue_link_t temp_bq[BQ_MAX_SIZE];
	pqueue_link_t x;

	for(max=-1,i=0;i < BQ_MAX_SIZE;i++){
		if((pq->bq)[i]!=NULL){
			if(max==-1 || compare_item((pq->bq)[i]->item,(pq->bq)[max]->item)>0){
				max=i;
			}
		}
	}

	copy_item(&max_item,&(pq->bq)[max]->item);

	for(i=0;i<BQ_MAX_SIZE;i++){
		temp_bq[i]=NULL;
	}

	x=(pq->bq)[max]->left;
	for(i=max-1;i>=0;i--){
		temp_bq[i]=x;
		x=x->right;
		temp_bq[i]->right=NULL;
	}

	free((pq->bq)[max]);
	(pq->bq)[max]=NULL;

	bqueue_join(pq->bq,temp_bq);

	return(max_item);
}

// change and delete unimplemented
void pqueue_change(pqueue_t pq,pqueue_link_t node,item_t new_item)
{
	
}

void pqueue_delete(pqueue_t pq,pqueue_link_t node)
{

}

/*
** The pqueue_join function join the binomial queues in pq1 and pq2,
** then save the result in the newly-created queue pq. Next destory
** the priority queue data types pq1 and pq2, finally return the resultant
** priority queue data type.
*/
pqueue_t pqueue_join(pqueue_t pq1,pqueue_t pq2)
{
	pqueue_t pq=pqueue_init(0);
	int i;

	bqueue_join(pq1->bq,pq2->bq);

	for(i=0;i<BQ_MAX_SIZE;i++){
		(pq->bq)[i]=(pq1->bq)[i];
	}

	pqueue_destroy(pq1);
	pqueue_destroy(pq2);

	return(pq);
}

void pqueue_print(pqueue_t pq)
{
	int i;

	for(i=0;i < BQ_MAX_SIZE;i++){
		print_2_power_heap((pq->bq)[i]);
	}
	putchar('\n');
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

static void print_2_power_heap(pqueue_link_t root)
{
	if(root==NULL){
		return;
	}

	print_item(root->item);
	putchar(' ');

	print_2_power_heap(root->left);
	print_2_power_heap(root->right);
}

#define test(A,B,C) (1*(A)+2*(B)+4*(C))
static void bqueue_join(pqueue_link_t *bq1,pqueue_link_t *bq2)
{
	int i;
	pqueue_link_t c;

	for(c=NULL,i=0;i<BQ_MAX_SIZE;i++){
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
