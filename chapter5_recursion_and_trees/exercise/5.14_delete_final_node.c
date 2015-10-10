link_t deleteFinal(link_t head)
{
	if(head->next==NULL){
		free(head);
		return(NULL);
	}
	
	head->next=return(head->next);
	
	return(head);
}
