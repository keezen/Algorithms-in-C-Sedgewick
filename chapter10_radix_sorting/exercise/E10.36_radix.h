#ifndef RADIX_H
#define RADIX_H

#define bitsword 32
#define bitsbyte 1
#define bytesword 32
#define R 2

#define digit(A,B) (((A) >> (bitsword-((B)+1)*bitsbyte)) & (R-1))
	
#endif
