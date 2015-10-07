#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"point.h"

typedef struct node* link_t;
struct node{
	point_t point;
	int number;
	link_t next;
};

link_t **grid;
int *array,*size;
int G,count=0,N;
double d;

int find_and_union(int p,int q)
{
	int i,j;	
	
	for(i=p;array[i]!=i;i=array[i])
		array[i]=array[array[i]];
	for(j=q;array[j]!=j;j=array[j]);
		array[j]=array[array[j]];
	if(i==j)
		return(0);
		
	if(size[i]<size[j]){
		array[i]=j;
		size[j]+=size[i];
	}else{
		array[j]=i;
		size[i]+=size[j];
	}

	return(1);
}

int is_connected(void)
{
	int count=0,i;

	for(i=0;i<N;i++)
		if(array[i]!=i)
			count++;
	if(count==N-1)
		return(1);
	
	return(0);		
}

link_t **malloc2d(int r,int c)
{
	link_t **t;
	int i;
	
	t=malloc(r*sizeof(link_t*));
	for(i=0;i<r;i++)
		t[i]=malloc(c*sizeof(link_t));

	return(t);
}

double rand_float(void)
{
	return(rand()/(double)RAND_MAX);
}

void grid_insert(double x,double y,int number)
{
	link_t t,s;
	int X,Y,i,j;
	
	t=malloc(sizeof(*t));
	t->point.x=x;
	t->point.y=y;
	t->number=number;

	X=x*G+1;
	Y=y*G+1;

	for(i=X-1;i<=X+1;i++)
		for(j=Y-1;j<=Y+1;j++)
			for(s=grid[i][j];s!=NULL;s=s->next)
				if(distance(t->point,s->point)<d){
					count++;
					find_and_union(t->number,s->number);
				}
	t->next=grid[X][Y];
	grid[X][Y]=t;	
}

int main(int argc,char *argv[])
{
	N=atoi(argv[1]);
	int i,j;

	d=atof(argv[2]);
	G=1/d;
	srand((unsigned)time(NULL));

	array=malloc(N*sizeof(int));
	size=malloc(N*sizeof(int));
	for(i=0;i<N;i++){
		array[i]=i;
		size[i]=1;	
	}

	grid=malloc2d(G+2,G+2);
	for(i=0;i<G+2;i++)
		for(j=0;j<G+2;j++)
			grid[i][j]=NULL;

	for(i=0;i<N;i++)
		grid_insert(rand_float(),rand_float(),i);

	printf("%d edges shorter than %f.\n",count,d);
	if(is_connected())
		printf("%d points can be connected with edges less than %f\n.",N,d);
	else
		printf("%d points can't be connected with edges less than %f\n.",N,d);

	return(0);
}
