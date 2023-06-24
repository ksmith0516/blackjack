/*
 * 	Deck.h
 * 		contents of deck
 */

#include "Card.h"
#include <vector>

#ifndef DECK_H_
#define DECK_H_

class Deck {
public:
	Deck();
	virtual ~Deck();
	std::vector<Card> getDeck();
	Card getCard(unsigned i);
	bool getUsed(unsigned i);
	unsigned getNumCardsInDeck();

private:
	void setDeck();
	std::vector<Card> deck;
	static constexpr unsigned numOfCardFaces = 13;
	static constexpr unsigned numCardsInDeck = 52;
	std::string suits[4] = {"clubs", "diamonds", "hearts", "spades"};
	std::string faces[numOfCardFaces] = {"two", "three", "four", "five", "six",
			"seven", "eight", "nine", "ten", "jack", "queen", "king", "ace"};
	unsigned values[numOfCardFaces] = {2,3,4,5,6,7,8,9,10,10,10,10,11};
};

#endif /* DECK_H_ */
