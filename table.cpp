//-----------------------------------------------------------
// Purpose: CPP file for the Table class.
//          This class cpp stores various People objects into an array
//			and utilized the array to preform different functions to
//			analyze the data.
// Author:  Jordan Lyle
//-----------------------------------------------------------
#include "table.h"
Table::Table()
{

}
Table::Table(const Table& table)
{
}

Table::~Table()
{
	delete head;
}
void Table::printTable()
{
	PersonNode* Print = head;
	while (Print != NULL)
	{
		Print->printPersonNode();
		Print = Print->getNext();
	}
}
bool Table::readFile()
{
	cout << "Enter filename: ";
	string filename = "";
	cin >> filename; // Takes the name of the file to be read.
	PersonNode* ptr;

	ifstream din;
	din.open(filename.c_str());
	if (din.fail()) // Decides to continue commands only if the file can be opened.
	{
		cout << "Error: could not open file" << endl;
		return 1;
	}
	else
	{
		while (!din.eof()) // Repeats until the file is done.
		{
			string First, Last, Info;
			int Birth, Death;
			din >> First >> Last >> Birth >> Death;
			getline(din, Info);                        
			data.setFirstName(First);
			data.setLastName(Last);
			data.setBirthYear(Birth);					// Gets all of the info from the file and stores it in the Person object.
			data.setDeathYear(Death);
			data.setContribution(Info);
			PersonNode* ptr = new PersonNode(First, Last, Birth, Death, Info); // Creates a new node for the list.
			if (head == NULL)
			{
				head = ptr;   // If list is empy then the list now has a node.
			}
			else
			{
				ptr->setNext(head); // If the list is not empty the new node is inserted in front of the head.
				head = ptr;
			}
			count++;
		}

	}
	return 0;
}
void Table::insertPerson()
{
	string First, Last, Info;
	int Birth, Death;
	cout << "Name: ";
	cin >> First;
	cout << "Last:";
	cin >> Last;
	cout << "Birth:";
	cin >> Birth;             // Same process as readFile except with user information.
	cout << "Death:";
	cin >> Death;
	cout << "Contribution:";
	cin.ignore();
	getline(cin,Info);
	cin.clear();
	Info = " " + Info;
	data.setFirstName(First);
	data.setLastName(Last);
	data.setBirthYear(Birth);
	data.setDeathYear(Death);
	data.setContribution(Info);
	PersonNode* ptr2 = new PersonNode(First, Last, Birth, Death, Info);
	if (head == NULL)
	{
		head = ptr2;
	}
	else
	{
		ptr2->setNext(head);
		head = ptr2;
	}
}
void Table::insertSortPerson()
{
	string First, Last, Info;
	int Birth, Death;
	cout << "Name: ";
	cin >> First;
	cout << "Last:";
	cin >> Last;
	cout << "Birth:";
	cin >> Birth;
	cout << "Death:";
	cin >> Death;
	cin.ignore();
	cout << "Contribution:";
	cin.clear();
	getline(cin,Info);
	Info = " " + Info;
	data.setFirstName(First);
	data.setLastName(Last);
	data.setBirthYear(Birth);
	data.setDeathYear(Death);
	data.setContribution(Info);
	PersonNode* ptr3 = new PersonNode(First, Last, Birth, Death, Info);
	PersonNode* curr = head;
	PersonNode* prev = head;
	while ((curr != NULL) && (curr->getBirthYear() > data.getBirthYear()))
	{
		prev = curr;
		curr = curr->getNext(); //If the list hasn't ended and the birth year is still greater than the node's year, continue searching.
	}
	if (curr == head)
	{
		ptr3->setNext(head); // If the current node is equal to the head at the end of the loop, insert node in front of head.
		head = ptr3;
	}
	else
	{
		prev->setNext(ptr3); // Else just put new node in between previous and current node.
		ptr3->setNext(curr);
	}
}
void Table::deletePerson()
{
	count = 0;
	string firstName;
	string lastName;
	PersonNode* curr = head;
	PersonNode* prev = head;
	cout << "Enter first name:";
	cin >> firstName;
	cout << "Enter last name:";
	cin >> lastName;
	while ((curr != NULL))
	{
		if ((curr->getFirstName() == firstName) && (curr->getLastName() == lastName)) 
		{								// Only remove from list if first name and last names are equal to the node.
			if (curr == head)
			{
				head = curr->getNext();
				count++;
			}
			else
			{
				prev->setNext(curr->getNext());       //If current node is not equal to head, then just route the previous node to the one after.
				count++;
			}
		}
		prev = curr;
		curr = curr->getNext();
	}
	if (count == 0)
	{
		cout << "No person of this name was found on this list" << endl;
	}
}
void Table::searchFirstName()
{
	count = 0;
	string firstName;
	PersonNode* curr = head;
	PersonNode* prev = head;
	cout << "Enter first name:";
	cin >> firstName;
	while ((curr != NULL))
	{
		if ((curr->getFirstName() == firstName))
		{
			curr->printPersonNode(); //If firstname is on the list, print the info of that person.
			count++;
		}
		prev = curr;
		curr = curr->getNext();
	}
	if (count == 0)
	{
		cout << "No person of this first name was found on this list" << endl;
	}

}
void Table::searchYear()
{
	count = 0;
	int birthYear;
	PersonNode* curr = head;
	PersonNode* prev = head;
	cout << "Enter birth year:";
	cin >> birthYear;
	while ((curr != NULL))
	{
		if ((int(curr->getBirthYear() / 10) == int(birthYear / 10)))  //Integers remove decimals so 1944 and 1940 end up being 194.4 and 194.0 which are equal to 194 == 194.
		{
			curr->printPersonNode();
			count++;
		}
		prev = curr;
		curr = curr->getNext();
	}
	if (count == 0)
	{
		cout << "No person of this birth year was found on this list" << endl;
	}

}
bool Table::writeFile()
{
	ofstream dout;
	dout.open("table.txt");
	if (dout.fail()) // Decides to continue commands only if the file can be opened.
	{
		cout << "Error: could not create file" << endl;
		return 1;
	}
	else
	{
		PersonNode* curr = head;
		while ((curr != NULL))
		{
			dout << curr->getFirstName() << " " << curr->getLastName() << " 		" << curr->getBirthYear() << " " << curr->getDeathYear() << " " << curr->getContribution() << endl;
			curr = curr->getNext();
			// Very similar to read file except outputting the list in the correct format.
		}
	}
	return 0;
}
