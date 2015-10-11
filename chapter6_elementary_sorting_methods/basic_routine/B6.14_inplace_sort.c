/*
** This function aims to sort the data array in place according
** to the sorted index array. Any element with a[i] == i is in
** place and does not need to be touched. Otherwise, save data[i]
** as temp and work through the cycle a[i], a[a[i]], a[a[a[i]]],
** and so on, until reaching the index i again. We follow the process
** again for the next element which is not in place, and continue in
** this manner, ultimately rearranging the entire file, moving each
** record only once.
*/
void inplace_sort(data_t *data,int *array,int N)
{
	int i,j,k;
	data_t temp;

	for(i=0;i<N;i++){
		temp=data[i];

		for(k=i;array[k]!=i;k=j){
			data[k]=data[array[k]];

			j=array[k];
			array[k]=k;
		}

		data[k]=temp;
		array[k]=k;	
	}
}
