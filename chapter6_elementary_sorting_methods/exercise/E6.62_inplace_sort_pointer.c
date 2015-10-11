/*
** This function assembles the function that rearranges the data
** array in place according to the sorted index array. But this 
** time, it is according to the sorted pointer array instead.
*/
void inplace_sort_pointer(data_t datas[],data_t *array[],int N)
{
	int i,j,k;
	data_t temp;

	for(i=0;i<N;i++){
		temp=datas[i];
	
		for(k=i;array[k] != &datas[i];){
			datas[k]=*array[k];

			j=k;
			k=array[j]-datas;
			array[j]=&datas[j];
		}

		datas[k]=temp;
		array[k]=&datas[k];
	}
}
