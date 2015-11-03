/*
** This program computes the zero point of a function in the interval (0,+inf), on 
** the assumption that this function is monotone and has only one zero point in (0,+inf).
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef double func_t(double);

double zero_point(func_t f);
double function(double x);

int N;


int main(int argc,char *argv[])
{
	double x;
	
	N=atoi(argv[1]);

	x=zero_point(function);
	printf("zero point: %.3f\n",x);

	return(0);
}

/*
** This implementation computes the zero point value, given the function f.
** The main idea is dividing the current interval into two parts to get a
** smaller interval.
*/
double zero_point(func_t f)
{
	double x1,x2,x;
	double y1,y2,y;
	double limit=1E-4;
	
	x1=0;
	y1=f(x1);

	x2=1;
	y2=f(x2);

	while(y1*y2>=0){
		x2*=2;
		y2=f(x2);
	}

	while(x2-x1>limit){
		x=(x1+x2)/2.0;
		y=f(x);

		if(y==0.0){
			return(x);
		}
		
		if(y1*y<0){
			x2=x;
			y2=f(x2);
			continue;
		}

		if(y1*y>0){
			x1=x;
			y1=f(x1);
			continue;
		}
	}
	return((x1+x2)/2.0);
}

double function(double x)
{
	double y;

	y=pow(x,x*x)-(double)N;

	return(y);
}
