#ifndef TABLE_H
#define TABLE_H
//-----------------------------------------------------------
// Purpose: Header file for the Table class.
//          This class is designed to store an array of Person
//          objects that describe a group of famous people.
//          The search methods locate and print information
//          about a specified subset of the famous people.
// Author:  Jordan Lyle
//-----------------------------------------------------------
#include "personNode.h"
#include <iostream>
#include <string>
using namespace std;

class Table
{
public:
	// Constructor methods
	Table();
	Table(const Table& table);
	~Table();

	// Input output methods
	void printTable();
	void insertPerson();
	void insertSortPerson();
	bool readFile();
	void deletePerson();
	bool writeFile();

	// Searching methods
	void searchFirstName();
	void searchYear();

private:
	// Object attributes
	PersonNode* head = NULL;
	PersonNode data;
	int count = 0;
};
#endif
