/*
 * Round.cpp
 *
 *  Created on: Jun 24, 2023
 *      Author: crujoness
 */

#include <vector>
#include <iostream>
#include "Round.h"
#include "Card.h"

Round::Round(Game *g) : game(g), stayOrOut(g->getNumPlayers() + 1, 'n'){	// +1 for dealer
	mapStartingHands();
	playRound();
}

Round::~Round() {
	// TODO Auto-generated destructor stub
}


void Round::mapStartingHands(){
	unsigned numPlayers = game->getNumPlayers();
	unsigned initialHandMax = 2;
	std::vector<Card> *deck = &(game->getShuffledDeck());

	for(unsigned i = 0; i < initialHandMax; ++i){

		addCardToPlayersStartingHand(deck, numPlayers);
		addCardToDealerStartingHand(deck);
	}

	//printHandsForTest();
}

void Round::addCardToPlayersStartingHand(std::vector<Card>* deck, const unsigned numPlayers){
	// deal one card to each player
	for(unsigned j = 0; j < numPlayers; ++j){
		std::string name = game->getPlayers()[j].getName();
		hands[name].push_back((*deck).back());
		(*deck).pop_back();
	}
}

void Round::addCardToDealerStartingHand(std::vector<Card>* deck){
	hands["zzdealer"].push_back((*deck).back());
	(*deck).pop_back();
}

void Round::printHandsForTest(){
	std::map<std::string, std::vector<Card>>::iterator it;
	for(it = hands.begin(); it != hands.end(); ++it){
		for(auto it2 = (*it).second.begin(); it2 != (*it).second.end(); ++it2){
			std::cout << it->first << std::endl;
			std::cout << it2->getValue() << std::endl;
		}
	}
}

void Round::playRound(){
	showHands();

	std::string action;

	while(!noMorePlayerActions()){
		unsigned cnt = 0;
		for(auto b = hands.begin(); b != hands.end(); ++b){
			if(stayOrOut[cnt] == 'n'){
				std::cout << (*b).first << ", hit or stay?  ";
				while(std::cin >> action){
					if(action == "hit" || action == "stay"){
						std::cout << std::endl;
						break;
					}
					std::cout << (*b).first << ", hit or stay?  ";
				}
				if(action == "hit"){
					b->second.push_back(game->getShuffledDeck().back());
					game->getShuffledDeck().pop_back();
					if(checkIfOver((*b).second)){
						stayOrOut[cnt] = 'y';
						std::cout << (*b).first << " is out" << std::endl;
					}
					showHands();
				} else if(action == "stay"){
					stayOrOut[cnt] = 'y';
				}
			}
			++cnt;
		}
	}
}

void Round::showHands(){
	unsigned cnt = 0;
	for(auto playerItr = hands.begin(); playerItr != hands.end(); ++playerItr){
		if(stayOrOut[cnt] == 'n' || stayOrOut[cnt] == 'Y'){
			std::cout << (*playerItr).first << ":\t\t";
			for(auto cardItr = (*playerItr).second.begin(); cardItr != (*playerItr).second.end(); ++cardItr){
				std::cout << (*cardItr).getFace() << " of " << (*cardItr).getSuit() << " & ";
			}
			std::cout << std::endl;
		}
		++cnt;
	}
}

bool Round::noMorePlayerActions(){
	for(unsigned i = 0; i < stayOrOut.size(); ++i){
		if(stayOrOut[i] == 'n' || stayOrOut[i] == 'N'){
			return 0;
		}
	}
	return 1;
}

bool Round::checkIfOver(std::vector<Card> &p) {
	unsigned sum = 0;
	//for(auto b = p.begin(); p != p.end(); ++p){
	for(unsigned i = 0; i < p.size(); ++i){
		sum += p[i].getValue();
	}
	std::cout << sum << std::endl;
	return sum > 21;
}
