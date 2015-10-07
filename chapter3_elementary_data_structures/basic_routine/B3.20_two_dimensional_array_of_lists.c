#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"point.h"

typedef struct node* link_t;
struct node{
	point_t point;
	link_t next;
};

link_t **grid;
int G,count=0;
double d;

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

void grid_insert(double x,double y)
{
	link_t t,s;
	int X,Y,i,j;
	
	t=malloc(sizeof(*t));
	t->point.x=x;
	t->point.y=y;

	X=x*G+1;
	Y=y*G+1;

	for(i=X-1;i<=X+1;i++)
		for(j=Y-1;j<=Y+1;j++)
			for(s=grid[i][j];s!=NULL;s=s->next)
				if(distance(t->point,s->point)<d)
					count++;
	t->next=grid[X][Y];
	grid[X][Y]=t;	
}

int main(int argc,char *argv[])
{
	int N=atoi(argv[1]);
	int i,j;

	d=atof(argv[2]);
	G=1/d;
	srand((unsigned)time(NULL));	

	grid=malloc2d(G+2,G+2);
	for(i=0;i<G+2;i++)
		for(j=0;j<G+2;j++)
			grid[i][j]=NULL;

	for(i=1;i<=N;i++)
		grid_insert(rand_float(),rand_float());

	printf("%d edges shorter than %f.\n",count,d);

	return(0);
}
