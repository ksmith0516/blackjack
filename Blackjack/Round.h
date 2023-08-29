/*
 * Round.h
 * 		initial deal
 * 			one to all players then dealer
 * 			second to all players then dealer
 * 		repeat until all players are out or staying
 * 			actions
 * 				hit
 * 				stay
 * 				double down (learn rules)
 *			calculate hands
 *				over 21 are out
 *
 */




#ifndef ROUND_H_
#define ROUND_H_

#include <vector>
#include <map>
#include "Game.h"

class Game;

class Round {
public:
	Round(Game *g);
	virtual ~Round();

private:
	Game *game;
	std::vector<char> stayOrOut;
	std::map<std::string, std::vector<Card>> hands;
	void dealInitialHands();
	void dealCard();
	void mapStartingHands();
	void addCardToPlayersStartingHand(std::vector<Card>* deck, unsigned numPlayers);
	void addCardToDealerStartingHand(std::vector<Card>* deck);
	void printHandsForTest();
	void playRound();
	void showHands();
	bool noMorePlayerActions();
	bool checkIfOver(std::vector<Card> &p);
};

#endif /* ROUND_H_ */
