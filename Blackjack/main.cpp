/*
 * features
 * 	specify number of players
 * 	randomize deck
 * 	could specify number of decks to mix in
 * 	keep track of handed-out and discarded cards
 * 	bets
 * 		pool per player
 * 		anty
 * 		track money
 * 	calc hands
 * 	compare to dealer
 * 	track wins
 *
 *
 *	*left off: calculating hands, eliminating players during a round
 *	*fixes:
 *		remove dealer from getting additional cards until all players are out or staying
 *		figure out aces as 11 or 1
 */

#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Deck.h"
#include "Game.h"

using namespace std;

int main(){

	cout << "Program started..." << endl;
	Game game(2,2,1001,1);

	cout << "Program terminated." << endl;
	return 0;
}

/* notes
 *
 * classes needed:
 * 	Dealer -> use until learning about inheritance
 * 		money
 * 		name
 * 		wins
 * 		actions
 * 			deal
 * 			request player's action
 * 			hit me
 * 			stay
 * 	Round
 * 		steps:
 * 			anty
 * 		hands per player
 * 		dealer's hand
 * 		anty
 * 		double down
 *
 *
 */
