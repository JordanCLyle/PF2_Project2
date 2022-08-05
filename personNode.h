#ifndef PERSONNODE_H
#define PERSONNODE_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PersonNode
{
public:
	// Constructor methods
	PersonNode();
	PersonNode(string firstName, string lastName, int birthYear, int deathYear, string contribution);
	~PersonNode();

	// Get and Set methods
	string getFirstName() const;
	string getLastName() const;
	int getBirthYear() const;
	int getDeathYear() const;
	string getContribution() const;
	PersonNode* getNext();

	void setNext(PersonNode* next);
	void setFirstName(string firstname);
	void setLastName(string lastname);
	void setBirthYear(int birthyear);
	void setDeathYear(int deathyear);
	void setContribution(string Contribution);

	// Other methods
	void printPersonNode();


private:
	PersonNode* next;
	// Object attributes
	string firstName;
	string lastName;
	int birthYear;
	int deathYear;
	string contribution;
};
#endif
