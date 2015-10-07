int number_of_vertices(int a,int b)
{
	for(i=0;i<V;i++)
		if(array[a][i]==1 && array[b][i]==1 && i!=a && i!=b)
			count++;

	return(count);
}
