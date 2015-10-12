/*
** Partition function without using a break statement.
*/
int partition(item_t *array,int left,int right)
{
	item_t v=array[right];
	int i,j;

	for(i=left;compare_item(array[i],v)<0;i++)
			;
	for(j=right-1;j>=left && compare_item(array[j],v)>0;j--)
			;

	while(i<j){
		swap_item(&array[i],&array[j]);

		for(;compare_item(array[i],v)<0;i++)
			;
		for(;j>=left && compare_item(array[j],v)>0;j--)
			;
	}

	swap_item(&array[i],&array[right]);

	return(i);
}
