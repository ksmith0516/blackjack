/*
 * Game.cpp
 *
 *  Created on: Jun 19, 2023
 *      Author: crujoness
 */

#include <iostream>
#include "Game.h"
#include <bits/stdc++.h>

Game::Game() {
	numPlayers = 0;
	numDecks = 0;
	anty = 0;
	maxRaise = 0;
}

Game::Game(unsigned players, unsigned decks, unsigned anty, unsigned raise) :
		numPlayers(players), numDecks(decks), anty(anty), maxRaise(raise){
	this->setDecks(numDecks);
	buildDeck();
	setPlayers(numPlayers);
	playGame();
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

unsigned Game::getMaxHand() const {
	return maxHand;
}

void Game::setNumPlayers(unsigned num){
	numPlayers = num;
}
unsigned Game::getNumPlayers() const {
	return numPlayers;
}
void Game::setPlayers(unsigned num){
	/*
	for(unsigned i = 0; i < num; ++i){
		Player p;
		players.push_back(p);
	}
	*/
	Player p("test1", 1000, 6);
	players= {p};
	Player p2("test2", 2250, 4);
	players.push_back(p2);
}
std::vector<Player> Game::getPlayers() {
	return players;
}
void Game::setNumDecks(unsigned num){
	numDecks = num;
}
unsigned Game::getNumDecks() const {
	return numDecks;
}
void Game::setDecks(unsigned num){
	for(unsigned i = 0; i < num; ++i){
		Deck d;
		decks.push_back(d);
	}
}
std::vector<Deck> Game::getDecks(){
	return decks;
}
std::vector<Card> &Game::getShuffledDeck(){
	return shuffledDeck;
}
void Game::setAnty(unsigned num){
	anty = num;
}
unsigned  Game::getAnty() const {
	return anty;
}
void  Game::setMaxRaise(unsigned num){
	maxRaise = num;
}
unsigned Game::getMaxRaise() const {
	return maxRaise;
}
void Game::playGame(){
	introduceGame();
	introducePlayers();
	//playRound();

	while(numPlayers >= 0 && playRound()){
		Round round(this);

		removePlayers();
	}

	endGame();
}
void Game::introduceGame(){
	std::cout << "Welcome to the best Blackjack game on Earth!" << std::endl;
	std::cout << "Today we have:" << std::endl << std::endl;
}
void Game::introducePlayers(){
	for(unsigned i = 0; i < numPlayers; ++i){
		std::cout << players[i].getName() << " with $ " << players[i].getMoney() << " and " << players[i].getWins() << " career wins." << std::endl << std::endl;
		if(i != numPlayers - 1){
			std::cout << "vs." << std::endl << std::endl;
		}
	}
}

bool Game::playRound(){
	char playRound;

	std::cout << "Play a round? (y/n) ";
	std::cin  >> playRound;
	std::cout << std::endl;

	if(playRound != 'y' && playRound != 'Y'){
		return 0;
	}

	return 1;
}

void Game::removePlayers(){
	for(auto b = players.begin(); b != players.end(); ){
		if((*b).getMoney() == 0){
			std::cout << (*b).getName() << " is out of money. Player removed." << std::endl;
			b = players.erase(b);
			--numPlayers;
		} else {
			++b;
		}
	}
}

int Game::endGame(){
	std::cout << "Thanks for playing. Toodles." << std::endl;
	return 0;
}

/* Private */
void Game::buildDeck(){
	Deck d;
	unsigned numCardsInDeck = d.getNumCardsInDeck();

	combineDecks(numCardsInDeck);

	shuffleDecks(numCardsInDeck);

}

void Game::combineDecks(unsigned numCardsInDeck){

	// combine decks - keeps normal sequential order
	for(unsigned i = 0; i < numDecks; ++i){
		for(unsigned j = 0; j < numCardsInDeck; ++j){
			shuffledDeck.push_back(decks[i].getCard(j));
		}
	}
}

void Game::shuffleDecks(unsigned numCardsInDeck){

	// shuffle combined deck
	srand(time(0));
	unsigned numCardsTotal = numCardsInDeck * numDecks;

	for(unsigned i = 0; i < numCardsTotal; ++i){
		int r = i + (rand() % (numCardsTotal - i));
		std::swap(shuffledDeck[i], shuffledDeck[r]);
	}
}
