#ifndef RADIX_H
#define RADIX_H

#define bytesword 2
#define bitsbyte 32
#define bitsword 64
#define R (1LL << bitsbyte)

#define digit(A,B) (((A) >> (bitsword-((B)+1)*bitsbyte)) & (R-1))
	
#endif
