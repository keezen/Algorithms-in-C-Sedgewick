#include<stdlib.h>
#include<stdio.h>
#include"matrix.h"

struct matrix{
	int r;
	int c;
	item_t **array;
};

static item_t **malloc2d(int r,int c)
{
	item_t **t;
	int i;
	
	t=malloc(r*sizeof(item_t*));
	for(i=0;i<r;i++)
		t[i]=malloc(c*sizeof(item_t));

	return(t);
}

matr_t matrixInit(int M,int N,int index_r,int index_c,item_t item)
{
	matr_t m=malloc(sizeof(*m));
	int i,j;

	m->r=M;
	m->c=N;
	m->array=malloc2d(M,N);

	m->array[index_r][index_c]=item;
	for(i=0;i<M;i++)
		for(j=0;j<N;j++)
			if(i!=index_r && j!=index_c)
				m->array[i][j]=0;

	return(m);
}

void matrixPrint(matr_t m)
{
	int i,j;

	for(i=0;i < m->r;i++){
		for(j=0;j < m->c;j++)
			printf("%d ",m->array[i][j]);
		putchar('\n');
	}
} 

static void matrixError(void)
{
	puts("Illegal Operation!");
}

matr_t matrixAdd(matr_t m1,matr_t m2)
{
	matr_t m;
	int i,j;

	if(m1->r != m2->r  ||  m1->c != m2->c){
		matrixError();
		return;
	} 

	m=matrixInit(m1->r,m1->c,0,0,0);
	for(i=0;i < m1->r;i++)
		for(j=0;j < m1->c;j++)
			m->array[i][j] = m1->array[i][j] + m2->array[i][j];

	return(m);
}

matr_t matrixNumMult(matr_t sour,int num)
{
	matr_t dest;
	int i,j;

	dest=matrixInit(sour->r,sour->c,0,0,0);
	for(i=0;i < sour->r;i++)
		for(j=0;j < sour->c;j++)
			dest->array[i][j] = num * sour->array[i][j];

	return(dest);
}

matr_t matrixMult(matr_t m1,matr_t m2)
{
	matr_t m;
	int i,j,k;

	if(m1->c != m2->r){
		matrixError();
		return;
	}

	m=matrixInit(m1->r,m2->c,0,0,0);
	for(i=0;i < m->r;i++)
		for(j=0;j < m->c;j++){
			m->array[i][j]=0;
			for(k=0;k < m1->c;k++)
				m->array[i][j] += m1->array[i][k] * m2->array[k][j];
 		}

	return(m);
}

void matrixDest(matr_t m)
{
	int i;

	for(i=0;i < m->r;i++)
		free(m->array[i]);
	free(m->array);
	free(m);
}
