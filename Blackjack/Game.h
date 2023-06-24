/*
 * 	Game.h
 * 		players
 * 		dealer
 * 		deck
 * 			create deck
 * 			number of each card left in deck (not in a hand or discarded)
 */

#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "Round.h"

class Game {
public:
	Game();
	Game(unsigned players, unsigned decks, unsigned anty, unsigned raise);
	virtual ~Game();

	unsigned getMaxHand() const;
	void setNumPlayers(unsigned num);
	unsigned getNumPlayers() const;
	void setPlayers(unsigned num);
	std::vector<Player> getPlayers();
	void setNumDecks(unsigned num);
	unsigned getNumDecks() const;
	void setDecks(unsigned num);
	std::vector<Deck> getDecks();
	std::vector<Card> getShuffledDeck();
	void setAnty(unsigned num);
	unsigned getAnty() const;
	void setMaxRaise(unsigned num);
	unsigned getMaxRaise() const;

private:
	void playGame();
	void introducePlayers();
	bool playRound();
	void removePlayers();
	int endGame();
	void shuffleDeck();
	//void swap (Card *a, Card *b);
	const unsigned maxHand = 21;
	unsigned numPlayers = 0;
	std::vector<Player> players;
	unsigned numDecks = 0;
	std::vector<Deck> decks;
	std::vector<Card> shuffledDeck;
	unsigned anty;
	unsigned maxRaise;
};

#endif /* GAME_H_ */
