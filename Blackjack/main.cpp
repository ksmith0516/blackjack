/* test
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
 */

#include <iostream>
#include <string>
#include <vector>
#include "Person.h";
#include "Deck.h"

using namespace std;

int main(){
/*
	unsigned numPlayers;
	cout << "Enter number of players: ";
	cin  >> numPlayers;
	cout << endl;

	vector<Person> players(numPlayers);
	for(unsigned i = 0; i < numPlayers; ++i){
		read(cin, players[i]);
	}

	cout << players[0].getName() << players[0].getMoney() << players[0].getWins() << endl;
	cout << players[1].getName() << players[1].getMoney() << players[1].getWins() << endl;
*/
	Deck deck;
	Card c = deck.getCard(1);
	cout << c.getFace() << endl;
	c = deck.getCard(2);
	cout << c.getFace() << endl;
	vector<Deck> decks(4, deck);


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
 * 	Game
 * 		players
 * 		dealer
 * 		deck
 * 			create deck
 * 			number of each card left in deck (not in a hand or discarded)
 * 	Round
 * 		hands per player
 * 		dealer's hand
 * 		anty
 * 		double down
 *
 *
 */
