int number_of_vertices(int a,int b)
{
	link_t t,s;

	for(t=head[a];t!=NULL;t=Next(t))
		for(s=head[b];s!=NULL;s=Next(s))
			if(Item(t)==Item(s))
				count++;

	return(count);
}
