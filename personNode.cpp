#include "table.h"

PersonNode::PersonNode()
{
	firstName = "";
	lastName = "";
	birthYear = 0; // Initializes private variables to default.
	deathYear = 0;
	contribution = "";
}
PersonNode::PersonNode(string FirstName, string LastName, int BirthYear, int DeathYear, string Contribution)
{
	firstName = FirstName;
	lastName = LastName;
	birthYear = BirthYear;
	deathYear = DeathYear;
	contribution = Contribution;
}

PersonNode::~PersonNode()
{
}

string PersonNode::getFirstName() const
{
	return firstName;
}
string PersonNode::getLastName() const
{
	return lastName;
}
int PersonNode::getBirthYear() const
{
	return birthYear;
}
int PersonNode::getDeathYear() const
{
	return deathYear;
}
string PersonNode::getContribution() const
{
	return contribution;
}
PersonNode* PersonNode::getNext()
{
	return next;
}
void PersonNode::setNext(PersonNode* Next)
{
	next = Next;
}
void PersonNode::setFirstName(string firstname)
{
	firstName = firstname;
}
void PersonNode::setLastName(string lastname)
{
	lastName = lastname;
}
void PersonNode::setBirthYear(int birthyear)
{
	birthYear = birthyear;
}
void PersonNode::setDeathYear(int deathyear)
{
	deathYear = deathyear;
}
void PersonNode::setContribution(string Contribution)
{
	contribution = Contribution;
}
void PersonNode::printPersonNode()
{
	cout << endl << getFirstName() << endl << getLastName() << endl;
	cout << getBirthYear() << endl << getDeathYear() << endl;         // Prints all of the information associated with the person
	cout << getContribution().substr(1) << endl << endl;			  // on the text file.
}
