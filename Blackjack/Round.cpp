/*
 * Round.cpp
 *
 *  Created on: Jun 24, 2023
 *      Author: crujoness
 */

#include <vector>
#include <iostream>
#include "Round.h"

Round::Round(Game *g) : game(g){
	std::cout << game->getAnty() << std::endl;
}

Round::~Round() {
	// TODO Auto-generated destructor stub
}
