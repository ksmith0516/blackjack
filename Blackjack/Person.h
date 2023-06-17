/*
 * 	Person.h
 * 		money
 * 		name
 * 		wins
 * 		actions? or do these go in Round?
 * 			hit me?
 * 			stay?
 *		hand
*/

#include <string>

#ifndef PERSON_H_
#define PERSON_H_

class Person {
public:
	Person();
	Person(std::string n, int m, unsigned int w);
	virtual ~Person();

	void setName(std::string n);
	std::string getName();

	void setMoney(int m);
	int getMoney();

	void setWins(unsigned w);
	unsigned getWins();

private:
	std::string name;
	int money;
	unsigned wins;

friend std::istream &read(std::istream &is, Person &person);
};

std::istream &read(std::istream &is, Person &person);

#endif /* PERSON_H_ */



