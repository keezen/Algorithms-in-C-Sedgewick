#ifndef RADIX_H
#define RADIX_H

#include<math.h>

#define bitsword 32
#define bitsbyte 1
#define bytesword 32
#define R (1 << bitsbyte)

/*
** This operation extracts the Bth byte of a binary word A, implemented by
** arithmetic operations. The arithmetic method is based on the following 
** property: if a is a positive integer, the bth digit of the radix-R representation
** of a is |a/R^b| mod R (the bth digit ranges from 0, counts from right, and || means
** floor function). 
*/
#define digit(A,B) (((int)floor((A)/pow(R,bytesword-1-B)))%R)
	
#endif
