#ifndef RADIX_H
#define RADIX_H

#define bytesword 2
#define bitsbyte 16
#define bitsword 32

#define R (1<<bitsbyte)

#define digit(A,B) (((A) >> (bitsword-((B)+1)*bitsbyte)) & (R-1))
	
#endif
