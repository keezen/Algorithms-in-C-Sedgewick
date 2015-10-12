/*
** This nonrecursive implementation of quicksort uses an explicit
** stack, replacing recursive calls with stack pushes(of the parameters)
** and pops, until the stack is empty. We put the larger of the two subfiles
** on the stack first to ensure the maximum stack depth for sorting N
** elements is lgN.
*/
void quick_sort(item_t *array,int left,int right)
{
	int i;
	int l,r;

	stackInit(right-left+1);
	stackPush(right);
	stackPush(left);

	while(!stackEmpty()){
		l=stackPop();
		r=stackPop();		
		if(r<=l)
			continue;

		i=partition(array,l,r);
		if(i-l > r-i){
			stackPush(i-1);
			stackPush(l);

			stackPush(r);
			stackPush(i+1);			
		}else{
			stackPush(r);
			stackPush(i+1);	

			stackPush(i-1);
			stackPush(l);	
		}
	}	
}
