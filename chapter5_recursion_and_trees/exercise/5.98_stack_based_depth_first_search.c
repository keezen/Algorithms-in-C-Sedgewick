void visit(int vertex)
{
	printf("%d ",vertex);
}

void Push(link_t head)
{
	if(head==NULL)
		return;

	Push(Next(head));

	if(visited[Item(head)]==0)
		stackPush(Item(head));
}

void traverse(int k,void (*visit)(int))
{
	link_t x;
	int t;
	
	stackInit(100);
	stackPush(k);

	while(!stackEmpty()){
		t=stackPop();
		if(visited[t]==0)
			visit(t);
		visited[t]=1;

		Push(adj[t]);
	}
}
