/*
** Revise of the nonrecursive quicksort such that it never
** puts on the stack subfiles with r<=l.
*/
void quick_sort(item_t *array,int left,int right)
{
	int i;
	int l,r;

	if(right<=left){
		return;
	}

	stackInit(right-left+1);

	stackPush(right);
	stackPush(left);

	while(!stackEmpty()){
		l=stackPop();
		r=stackPop();		

		i=partition(array,l,r);
		if(i-l > r-i){
			if(i-1>l){
				stackPush(i-1);
				stackPush(l);
			}

			if(r>i+1){
				stackPush(r);
				stackPush(i+1);
			}			
		}else{
			if(r>i+1){
				stackPush(r);
				stackPush(i+1);	
			}
			
			if(i-1>l){
				stackPush(i-1);
				stackPush(l);
			}	
		}
	}	
}
