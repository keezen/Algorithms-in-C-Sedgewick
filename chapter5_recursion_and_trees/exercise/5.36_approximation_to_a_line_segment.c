#include<stdio.h>
#include"point.h"

#define M 20
#define Nmax 100

point_t array[Nmax];
int top=0;

void reverse(point_t array[])
{
	int i,mid=(top-1)/2;
	point_t t;

	for(i=0;i<=mid;i++){
		t=array[i];
		array[i]=array[top-1-i];
		array[top-1-i]=t;
	}

}

void draw(point_t begin,point_t end)
{
	point_t mid=newPoint((X(begin)+X(end))/2,(Y(begin)+Y(end))/2);;

	if(eqPoint(begin,mid) || eqPoint(mid,end)){
		if(X(begin)!=X(end) && Y(begin)!=Y(end)){
			point_t x=newPoint(X(end),Y(begin));
			array[top++]=x;
		}
	
		freePoint(mid);
		return;
	}

	draw(begin,mid);
	array[top++]=mid;
	draw(mid,end);
}

void drawLine(point_t begin,point_t end)
{
	if(X(begin)>X(end)){
		array[top++]=end;
		draw(end,begin);
		array[top++]=begin;

		reverse(array);
	
		return;		
	}

	array[top++]=begin;
	draw(begin,end);
	array[top++]=end;
}

void printLine(point_t array[])
{
	int i;

	for(i=0;array[i]!=NULL;i++)
		printf("(%d,%d)\n",X(array[i]),Y(array[i]));
}

int main(void)
{
	point_t begin,end;
	int i;

	begin=newPoint(1,1);
	end=newPoint(5,5);

	for(i=0;i<Nmax;i++)
		array[i]=NULL;

	drawLine(begin,end);

	printLine(array);

	return(0);
}
