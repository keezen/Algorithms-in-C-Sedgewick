#ifndef ITEM_H
#define ITEM_H

enum card {JOKER,ACE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,TEN,JACK,QUEEN,KING};
enum suit {DIAMONDS,CLUBS,HEARTS,SPADES};	
typedef struct{
	enum card card;
	enum suit suit;
	
} card_t;
#define eq(A,B) (A.card==B.card && A.suit==B.suit)
#define ITEMshow(A) switch(A.card){case JOKER:printf("JOKER");break;	case ACE:printf("ACE");break;	case TWO:printf("TWO");break;	case THREE:printf("THREE");break;	case FOUR:printf("FOUR");break;	case FIVE:printf("FIVE");break;	case SIX:printf("SIX");break;	case SEVEN:printf("SEVEN");break;	case EIGHT:printf("EIGHT");break;	case NINE:printf("NINE");break;	case TEN:printf("TEN");break;	case JACK:printf("JACK");break;	case QUEEN:printf("QUEEN");break;	case KING:printf("KING");break;};printf(" of ");switch(A.suit){case DIAMONDS:printf("DIAMONDS");break;	case CLUBS:printf("CLUBS");break;	case HEARTS:printf("HEARTS");break;	case SPADES:printf("SPADES");break;}

#endif
