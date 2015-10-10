#include<stdio.h>
#include"stack.h"
#include"dirlist.h"

#define V 8

link_t adj[V];
int visited[V]={0};

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

void print_list(link_t head[])
{
	link_t x;
	int i;

	for(i=0;i<V;i++){
		printf("%d:",Item(head[i]));
		for(x=Next(head[i]);x!=NULL;x=Next(x))
			printf("%d ",Item(x));
		putchar('\n');
	}
}

int main(void)
{
	link_t t;
	int i,j,start=0;
	FILE *fp;

	fp=fopen("adjacency_list_graph_traversal_depth_first_search_stack.dat","r");

	for(i=0;i<V;i++){
		adj[i]=allocNode(i);
		adj[i]->next=NULL;
	}

	while(fscanf(fp,"%d%d",&i,&j)==2){
		t=allocNode(j);
		insertNext(adj[i],t);
		t=allocNode(i);
		insertNext(adj[j],t);
	}

	fclose(fp);

	print_list(adj);

	putchar('\n');
	puts("traverse:");
	traverse(start,visit);
	putchar('\n');

	return(0);
}
