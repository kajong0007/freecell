#include <stdio.h>
#include <string.h>

#define ACE 1
#define JACK 11
#define QUEEN 12
#define KING 13

/* This is the new deck order of a Bicycle Deck.
 * I am taking liberties with the card order in these suits.
 * In a new deck, it's in the order below (when face up),
 * ACE through KING for the first two, but KING through
 * ACE for the last two (with the "kissing kings" in the center).
 * I have coded this to have the deck ACE through KING all the way through.
 */
#define SPADES 0
#define DIAMONDS 1
#define CLUBS 2
#define HEARTS 3 

struct CARD {
	unsigned int suit:2;
	unsigned int val:4;
};

struct SUIT {
	unsigned int suit:2;
	struct CARD cards[13];
};

struct DECK {
	struct CARD cards[52];
};

int valToChar (struct CARD inputCard);
int sameSuit (struct CARD oneCard, struct CARD otherCard);
int sameColor (struct CARD oneCard, struct CARD otherCard);

int
main (void)
{
	/* Defining every card is going to take a long time... */
	struct SUIT shovel;
	shovel.suit = SPADES;
	struct CARD aceS;
	struct CARD twoS;
	struct CARD thrS;
	struct CARD fouS;
	struct CARD fivS;
	struct CARD sixS;
	struct CARD sevS;
	struct CARD eigS;
	struct CARD ninS;
	struct CARD tenS;
	struct CARD jakS;
	struct CARD queS;
	struct CARD kinS;

	shovel.cards[0] = aceS;
	shovel.cards[1] = twoS;
	shovel.cards[2] = thrS;
	shovel.cards[3] = fouS;
	shovel.cards[4] = fivS;
	shovel.cards[5] = sixS;
	shovel.cards[6] = sevS;
	shovel.cards[7] = eigS;
	shovel.cards[8] = ninS;
	shovel.cards[9] = tenS;
	shovel.cards[10] = jakS;
	shovel.cards[11] = queS;
	shovel.cards[12] = kinS;

	struct SUIT stone;
	stone.suit = DIAMONDS;
	struct CARD aceD;
	struct CARD twoD;
	struct CARD thrD;
	struct CARD fouD;
	struct CARD fivD;
	struct CARD sixD;
	struct CARD sevD;
	struct CARD eigD;
	struct CARD ninD;
	struct CARD tenD;
	struct CARD jakD;
	struct CARD queD;
	struct CARD kinD;

	stone.cards[0] = aceD;
	stone.cards[1] = twoD;
	stone.cards[2] = thrD;
	stone.cards[3] = fouD;
	stone.cards[4] = fivD;
	stone.cards[5] = sixD;
	stone.cards[6] = sevD;
	stone.cards[7] = eigD;
	stone.cards[8] = ninD;
	stone.cards[9] = tenD;
	stone.cards[10] = jakD;
	stone.cards[11] = queD;
	stone.cards[12] = kinD;

	struct SUIT stick;
	stick.suit = CLUBS;
	struct CARD aceC;
	struct CARD twoC;
	struct CARD thrC;
	struct CARD fouC;
	struct CARD fivC;
	struct CARD sixC;
	struct CARD sevC;
	struct CARD eigC;
	struct CARD ninC;
	struct CARD tenC;
	struct CARD jakC;
	struct CARD queC;
	struct CARD kinC;

	stick.cards[0] = aceC;
	stick.cards[1] = twoC;
	stick.cards[2] = thrC;
	stick.cards[3] = fouC;
	stick.cards[4] = fivC;
	stick.cards[5] = sixC;
	stick.cards[6] = sevC;
	stick.cards[7] = eigC;
	stick.cards[8] = ninC;
	stick.cards[9] = tenC;
	stick.cards[10] = jakC;
	stick.cards[11] = queC;
	stick.cards[12] = kinC;

	struct SUIT soul;
	soul.suit = HEARTS;
	struct CARD aceH;
	struct CARD twoH;
	struct CARD thrH;
	struct CARD fouH;
	struct CARD fivH;
	struct CARD sixH;
	struct CARD sevH;
	struct CARD eigH;
	struct CARD ninH;
	struct CARD tenH;
	struct CARD jakH;
	struct CARD queH;
	struct CARD kinH;

	soul.cards[0] = aceH;
	soul.cards[1] = twoH;
	soul.cards[2] = thrH;
	soul.cards[3] = fouH;
	soul.cards[4] = fivH;
	soul.cards[5] = sixH;
	soul.cards[6] = sevH;
	soul.cards[7] = eigH;
	soul.cards[8] = ninH;
	soul.cards[9] = tenH;
	soul.cards[10] = jakH;
	soul.cards[11] = queH;
	soul.cards[12] = kinH;

	int i;
	int j;

	for (i = 0; i < 4; i++){
		for (j = 0; j < 13; j++){
			switch (i){
				case 0:
					shovel.cards[j].val = j;
					shovel.cards[j].suit = i;
					break;
				case 1:
					stone.cards[j].val = j;
					stone.cards[j].suit = i;
					break;
				case 2:
					stick.cards[j].val = j;
					stick.cards[j].suit = i;
					break;
				case 3:
					soul.cards[j].val = j;
					soul.cards[j].suit = i;
					break;
			}
		}
	}
	
}

int
valToChar (struct CARD inputCard)
{
	int output;
	if ((inputCard.val > 1) && (inputCard.val <= 10)) {
		output = inputCard.val + 48;
	} else {
		switch ( inputCard.val ){
			case ACE:
				output = 'A';
				break;
			case JACK:
				output = 'J';
				break;
			case QUEEN:
				output = 'Q';
				break;
			case KING:
				output = 'K';
				break;
			default:
				output = '?';
				break;
		}
	}
	return (output);
}

int
sameSuit (struct CARD oneCard, struct CARD otherCard)
{
	int same = 0;
	if (!((oneCard.suit & otherCard.suit) == 0)){
		same = 1;
	}
	return (same);
}

int
sameColor (struct CARD oneCard, struct CARD otherCard)
{
	int same = 0;
	if (oneCard.suit == otherCard.suit){
		same = 1;
	}
	return (same);
}
