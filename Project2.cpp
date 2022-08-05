#include <iostream>
#include "table.h"
using namespace std;

int main()
{
	Table reading;
	int i = 0;
	while (i == 0) // Loops the selection interface until the user is done.
	{
		cout << endl << "1) Read in a file." << endl;
		cout << "2) Insert person into the file." << endl;  // Gives selection of commands.
		cout << "3) Sorted insert by birth year." << endl;
		cout << "4) Delete person in list." << endl;
		cout << "5) Search list by first name." << endl;
		cout << "6) Search list by birth year." << endl;
		cout << "7) Write list into a text file." << endl;
		cout << "8) Print the list." << endl;
		cout << "9) Quit." << endl;
		cout << "Choose your selection number: ";
		int selection;
		cin >> selection;
		switch (selection) // Decides which method to call based on the command.
		{
			case 1:
			{
				if (reading.readFile() == 1)
				{
					return 0;
				}
				break;
			}
			case 2:
			{
				reading.insertPerson();
				break;
			}
			case 3:
			{
				reading.insertSortPerson();
				break;
			}
			case 4:
			{
				reading.deletePerson();
				break;
			}
			case 5:
			{
				reading.searchFirstName();
				break;
			}
			case 6:
			{
				reading.searchYear();
				break;
			}
			case 7:
			{
				if (reading.writeFile() == 1)
				{
					return 0;
				}
				break;
			}
			case 8:
			{
				reading.printTable();
				break;
			}
			default:
			{
				i = 1; // Tells the interface loop to stop when the user decides to quit.
				break;
			}
		}
	}
	return 0;
}
