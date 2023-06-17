/*
 * 	Deck
 * 		contents of deck
 * 		*assumes normal 2-ace deck with no jokers
 */

#include "Deck.h"
#include <iostream>

Deck::Deck() {
	setDeck();
}

Deck::~Deck() {
	// TODO Auto-generated destructor stub
}

void Deck::setDeck(){
	for(auto s : suits){
		for(unsigned i = 0; i < numOfCardFaces; ++i){
			Card c(faces[i], values[i], s);
			deck.push_back(c);
			//std::cout << c.getFace() << " " << c.getValue() << " " << c.getSuit() << std::endl;
		}
	}
}

std::vector<Card> Deck::getDeck() {
	return deck;
}

Card Deck::getCard(int index){
	return deck[index];
}
