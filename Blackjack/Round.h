/*
 * Round.h
 *      start round (bool)
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
#include "Game.h"

class Game;

class Round {
public:
	Round(Game *g);
	virtual ~Round();

private:
	Game *game;
};

#endif /* ROUND_H_ */
