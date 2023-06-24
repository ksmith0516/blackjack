/*
 * 	Card.h
 * 		suit
 * 		face
 * 		value
 * 			how to handle aces?
 */


#ifndef CARD_H_
#define CARD_H_

#include <string>

class Card {
public:
	Card();
	Card(std::string f, unsigned v, std::string s);
	virtual ~Card();

	Card getCard(Card &c);
	void setFace(std::string f);
	std::string getFace() const;
	void setValue(unsigned v);
	unsigned getValue() const;
	void setSuit(std::string s);
	std::string getSuit() const;
	unsigned getOtherAceValue();

	// add function to print face and suit

private:
	std::string face;	// i.e. name of card
	unsigned value;
	std::string suit;
	bool isAce();
};

#endif /* CARD_H_ */
