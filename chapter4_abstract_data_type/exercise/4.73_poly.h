#ifndef POLY_H
#define POLY_H

typedef struct poly* poly_t;
poly_t polyTerm(double coef,int exp);
poly_t polyAdd(poly_t,poly_t);
poly_t polyMult(poly_t,poly_t);
double polyEval(poly_t,double);
void polyShow(poly_t);
void polyDestroy(poly_t);
poly_t polyCopy(poly_t);
poly_t polyInte(poly_t);
poly_t polyDiff(poly_t);

#endif
