/*
** Implement binomial queue such that Property 9.7 holds, by maintaining
** a sentinel pointer to mark the point where the loops should terminate.
** Every binomial queue has an unique sentinel that is not shared with with
** other ones.
*/
#include<stdlib.h>
#include<stdio.h>
#include"pqueue_full.h"
#include"item.h"

/*
** The max size of the binomial queue determines that the maximum number 
** of elements in the priority queue is (2^BQ_MAX_SIZE-1), that is very
** large when BQ_MAX_SIZE is not so large.
*/
#define BQ_MAX_SIZE 100

struct PQUEUE_NODE{
	item_t item;
	pqueue_link_t left;
	pqueue_link_t right;
};
struct PQUEUE{
	pqueue_link_t *bq;
	pqueue_link_t sentinel;
};

static pqueue_link_t pair_2_power_heap(pqueue_link_t roota,pqueue_link_t rootb);
static void print_2_power_heap(pqueue_link_t root);
static void bqueue_join(pqueue_link_t *bq1,pqueue_link_t *bq2,pqueue_link_t sentinel1,pqueue_link_t sentinel2);

pqueue_t pqueue_init(int Nmax)
{
	pqueue_t pq;
	int i;

	pq=malloc(sizeof(*pq));
	pq->bq=malloc(BQ_MAX_SIZE*sizeof(pqueue_link_t));
	pq->sentinel=malloc(sizeof(struct PQUEUE_NODE));
	(pq->bq)[0]=pq->sentinel;

	for(i=1;i<BQ_MAX_SIZE;i++){
		(pq->bq)[i]=NULL;
	}

	return(pq);
}

int pqueue_empty(pqueue_t pq)
{
	return((pq->bq[0])==pq->sentinel);
}

/*
** To insert a node into a binomail queue, we first make the node into a
** 1-heap, identify it as a carray 1-heap, and then iterate the following
** process starting at i=0. If the binomial queue has no 2^i-heap, we put
** the carray 2^i-heap into the queue. If the binomial queue has a 2^i-heap,
** we combine that with the carry to make a 2^(i+1)-heap, increment i, and
** iterate until finding an empty heap position int the binomial queue. We
** adopt the convention of representing nulll links with NULL.
*/
pqueue_link_t pqueue_insert(pqueue_t pq,item_t item)
{
	pqueue_link_t new,c;
	int i;

	new=malloc(sizeof(*new));
	copy_item(&new->item,&item);
	new->left=NULL;
	new->right=NULL;

	for(c=new,i=0;;i++){
		if((pq->bq)[i]==pq->sentinel){
			(pq->bq)[i]=c;
			(pq->bq)[i+1]=pq->sentinel;
			break;
		}

		if((pq->bq)[i]==NULL){
			(pq->bq)[i]=c;
			break;
		}

		c=pair_2_power_heap(c,(pq->bq)[i]);
		(pq->bq)[i]=NULL;
	}

	return(new);
}

/*
** Delete the maximum in a binomial queue. We first scan the root nodes to
** find the maximum, and remove the 2-power heap containting the maximum
** from the binomial queue. We then remove the root node from its 2-power
** heap and temporarily build a binomial queue that contains the remaining
** constituent parts of the 2-power heap. Finally, we use the bqueue_join
** operation to merge this binomial queue back into the original binomial
** queue.
*/
item_t pqueue_del_max(pqueue_t pq)
{
	int i,max;
	item_t max_item;
	pqueue_link_t temp_bq[BQ_MAX_SIZE];
	pqueue_link_t x;

	for(max=-1,i=0;(pq->bq)[i]!=pq->sentinel;i++){
		if((pq->bq)[i]!=NULL){
			if(max==-1 || compare_item((pq->bq)[i]->item,(pq->bq)[max]->item)>0){
				max=i;
			}
		}
	}

	copy_item(&max_item,&(pq->bq)[max]->item);

	temp_bq[max]=pq->sentinel;
	for(i=0;i<max;i++){
		temp_bq[i]=NULL;
	}

	x=(pq->bq)[max]->left;
	for(i=max-1;i>=0;i--){
		temp_bq[i]=x;
		x=x->right;
		temp_bq[i]->right=NULL;
	}

	free((pq->bq)[max]);
	if((pq->bq)[max+1]==pq->sentinel){
		(pq->bq)[max]=pq->sentinel;
	}else{
		(pq->bq)[max]=NULL;
	}

	bqueue_join(pq->bq,temp_bq,pq->sentinel,pq->sentinel);

	return(max_item);
}

// change and delete unimplemented
void pqueue_change(pqueue_t pq,pqueue_link_t node,item_t new_item)
{
	
}

void pqueue_delete(pqueue_t pq,pqueue_link_t node)
{

}

pqueue_t pqueue_join(pqueue_t pq1,pqueue_t pq2)
{
	int max_digit;

	bqueue_join(pq1->bq,pq2->bq,pq1->sentinel,pq2->sentinel);

	return(pq1);
}

void pqueue_print(pqueue_t pq)
{
	int i;

	for(i=0;(pq->bq)[i]!=pq->sentinel;i++){
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

/*
** This is the function that joins two binomial queues into the first one.
** This code mimics the operation of adding two binary numbers. Proceeding
** from right to left with an initial carray bit of 0, we treat the eight
** possible cases (all possible values of the operands and carry bits) in
** a straightforward manner. For example, case 2 corresponds to the operand
** bits being both 1 and the carray 0. Then, the result is 0, but the carry
** is 1 (the result of adding the operand bits).
*/
#define test(A,B,C) (1*(A)+2*(B)+4*(C))
static void bqueue_join(pqueue_link_t *bq1,pqueue_link_t *bq2,pqueue_link_t sentinel1,pqueue_link_t sentinel2)
{
	int i;
	pqueue_link_t c;

	for(c=NULL,i=0;bq1[i]!=sentinel1 && bq2[i]!=sentinel2;i++){
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

	if(bq1[i]==sentinel1){
		for(;bq2[i]!=sentinel2;i++){
			if(c!=NULL && bq2[i]!=NULL){
				c=pair_2_power_heap(bq2[i],c);
				bq1[i]=NULL;
				continue;	
			}
			
			if(c==NULL){
				bq1[i]=bq2[i];
			}else{
				bq1[i]=c;
				c=NULL;
			}
		}

		if(c!=NULL){
			bq1[i]=c;
			bq1[i+1]=sentinel1;
			c=NULL;
		}else{
			bq1[i]=sentinel1;
		}
	}else{
		for(;bq1[i]!=sentinel1;i++){
			if(c!=NULL && bq1[i]!=NULL){
				c=pair_2_power_heap(bq1[i],c);
				bq1[i]=NULL;
				continue;
			}

			if(c!=NULL){
				bq1[i]=c;
				c=NULL;
			}
		}

		if(c!=NULL){
			bq1[i]=c;
			bq1[i+1]=sentinel1;
			c=NULL;
		}
	}
}
