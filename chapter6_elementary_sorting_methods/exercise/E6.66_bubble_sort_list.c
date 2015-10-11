/*
** The bubble sort function for the linked list. We perform
** exchanges in the original linked list, just as in the array
** version.
*/
link_t bubble_sort_list(link_t head)
{
	link_t x;
	link_t previous,current,t;

	for(x=head;x->next != NULL;x=x->next)
		;

	while(x!=head){
		previous=head;
		current=head->next;
		while(current != x  &&  x->next != current){
			/*
			** If the current item is larger than the next item,
			** we exchange their positions in the linked list.
			*/
			if(compare_item(current->item,current->next->item)>0){
				t=current->next;
				current->next=t->next;
		
				t->next=current;
				previous->next=t;
	
				previous=t;
			}else{
				previous=current;
				current=current->next;
			}
		}

		x=previous;
	}

	return(head);
}	
