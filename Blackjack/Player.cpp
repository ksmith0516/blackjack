/*
 * Player.cpp
 *
 *  Created on: Jun 16, 2023
 *      Author: crujoness-laptop
 */

#include "Player.h"
#include <string>
#include <iostream>
#include <vector>

Player::Player() {
	askName();
	askMoney();
	askWins();
}

Player::Player(std::string n, int m, unsigned int w)
		: name(n), money(m), wins(w){
}

Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::setName(std::string n){
	name = n;
}
std::string Player::getName(){
	return name;
}
void Player::askName(){
	std::string n;
	std::cout << "Enter player's name: ";
	std::cin >> n;
	std::cout << std::endl;
	name = n;
}
void Player::askMoney(){
	unsigned m;
	std::cout <<"Enter player's money amount: ";
	std::cin >> m;
	std::cout << std::endl;
	money = m;
}
void Player::askWins(){
	unsigned w;
	std:: cout << "Enter player's win total: ";
	std::cin >> w;
	std::cout << std::endl;
	wins = w;
}
void Player::setMoney(int m){
	money = m;
}

int Player::getMoney(){
	return money;
}

void Player::setWins(unsigned w){
	wins = w;
}
unsigned Player::getWins(){
	return wins;
}

std::istream &read(std::istream &is, Player &person){
	std::cout << "Enter name, starting money amount, and lifetime wins" << std::endl;
	is >> person.name >> person.money >> person.wins;
	return is;
}
