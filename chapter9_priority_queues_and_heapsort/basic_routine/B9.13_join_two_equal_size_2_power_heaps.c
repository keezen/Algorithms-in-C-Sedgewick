/*
** This function joins two equal-size 2-power heaps into one. We need to change
** only a few links to combine two equal-sized 2-power heaps into onde 2-power 
** heap that is twice the size of the original size. This pair_2_power_heap procedure
** is one key to the efficiency of the binomial queue algorithm. 
*/
pqueue_link_t pair_2_power_heap(pqueue_link_t roota,pqueue_link_t rootb)
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
