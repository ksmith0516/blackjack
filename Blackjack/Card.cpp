/*
 * Card.cpp
 *
 *  Created on: Jun 17, 2023
 *      Author: crujoness
 */

#include "Card.h"

Card::Card() {
	face = "faceless";
	value = 0;
	suit = "suitless";
}

Card::Card(std::string f, unsigned v, std::string s) :
		face(f), value(v), suit(s){
}

Card Card::getCard(Card &c) {
	return c;
}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

void Card::setFace(std::string f){
	face = f;
}

std::string Card::getFace() const {
	return face;
}

void Card::setValue(unsigned v){
	value = v;
}

unsigned Card::getValue() const {
	return value;
}

void Card::setSuit(std::string s){
	suit = s;
}

std::string Card::getSuit() const {
	return suit;
}

bool Card::isAce() {
	return face == "ace";
}
unsigned Card::getOtherAceValue() {
	return isAce() ? 1 : 0;
}
