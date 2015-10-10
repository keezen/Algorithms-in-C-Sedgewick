link_t delete(link_t x,item_t v)
{
	if(x==NULL)
		return(NULL);

	if(x->left==NULL && x->right==NULL && eq(x->item,v)){
		free(x);
		return(NULL);
	}


	x->left=delete(x->left,v);
	x->right=delete(x->right,v);

	return(x);
}
