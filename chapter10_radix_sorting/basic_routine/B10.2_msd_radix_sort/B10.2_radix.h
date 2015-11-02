/*
** This headfile includes the definitions for the number of bits in a word,
** the number of bits in a byte, the number of bytes in a word, and the radix
** number R. The operation extrating the Bth byte from the word A is also
** included here. Particularly, bitsword should be the product of bitsbyte and
** bytesword.
*/
#ifndef RADIX_H
#define RADIX_H

#define bytesword 32
#define bitsbyte 1
#define bitsword 32
#define R (1 << bitsbyte)

/*
** This operation extracts the Bth byte of a binary word A, implemented by
** bitwise and(&) and shift(>>) operations. (R-1) is a mask to zero out all
** the bits except those of the desired byte. B is in the range from 0 to
** (bytesword-1), just like an array index.
*/
#define digit(A,B) (((A) >> (bitsword-((B)+1)*bitsbyte)) & (R-1))
	
#endif
