typedef enum {ACE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHR,NINE,TEN,JACK,QUEEN,KING} rank_t;
typedef enum {DIAMONDS,CLUBS,HEARTS,SPADES} suit_t;

typedef struct{
	rank_t rank;
	suit_t suit;
} card_t;
