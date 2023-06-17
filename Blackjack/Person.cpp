/*
 * Person.cpp
 *
 *  Created on: Jun 16, 2023
 *      Author: crujoness-laptop
 */

#include "Person.h"
#include <string>
#include <iostream>
#include <vector>

Person::Person() {
	name = "unknown";
	money = 0;
	wins = 0;
}

Person::Person(std::string n, int m, unsigned int w)
		: name(n), money(m), wins(w){
}

Person::~Person() {
	// TODO Auto-generated destructor stub
}

void Person::setName(std::string n){
	name = n;
}
std::string Person::getName(){
	return name;
}
void Person::setMoney(int m){
	money = m;
}

int Person::getMoney(){
	return money;
}

void Person::setWins(unsigned w){
	wins = w;
}
unsigned Person::getWins(){
	return wins;
}

std::istream &read(std::istream &is, Person &person){
	std::cout << "Enter name, starting money amount, and lifetime wins" << std::endl;
	is >> person.name >> person.money >> person.wins;
	return is;
}
