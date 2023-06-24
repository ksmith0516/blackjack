/*
 * 	Player.h
 * 		money
 * 		name
 * 		wins
 * 		actions? or do these go in Round?
 * 			hit me?
 * 			stay?
 *		hand
*/

#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Player {
public:
	Player();
	Player(std::string n, int m, unsigned int w);
	virtual ~Player();

	void setName(std::string n);
	std::string getName();
	void askName();
	void askMoney();
	void askWins();
	void setMoney(int m);
	int getMoney();
	void setWins(unsigned w);
	unsigned getWins();

private:
	std::string name;
	int money;
	unsigned wins;

friend std::istream &read(std::istream &is, Player &person);
};

std::istream &read(std::istream &is, Player &person);

#endif /* PERSON_H_ */



