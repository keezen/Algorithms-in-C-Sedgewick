/*
** The insertion sort function for a linked list. This implementation maintains
** two linked lists, one is the input, and the other is the output. While the input
** is not empty, take out the front element from it, and insert it in the proper 
** position of the output list.
*/
link_t insertion_sort_list(link_t head)
{
	link_t out,t;
	link_t current,*plink;
	
	out=NULL;
	while(head != NULL){
		t=head;
		head=head->next;
		t->next=NULL;

		/*
		** Insert the taken-out element in a proper position. plink is
		** a pointer, it points to such a variable, which contains the
		** pointer to the current node.
		*/
		plink=&out;
		current=out;
		while(current!=NULL && compare_item(current->item,t->item)<0){
			plink=&(current->next);
			current=current->next;
		}

		t->next=current;
		*plink=t;
	}

	return(out);
}	
