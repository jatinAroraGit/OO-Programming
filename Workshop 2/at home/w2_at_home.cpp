/***********************************************************
Workshop 2: HOME
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@


// PURPOSE - this file contains the main function which is used to strore and display the information of Kingdoms entered by user
****************************************************************/

#include<iostream>
using namespace std;
#include "Kingdom.h"
using namespace SICT;

void read(Kingdom&);

int main() {
	int count = 0; // the number of kingdoms in the array
	Kingdom* pKingdom = nullptr;
	// declared the pKingdom pointer here

	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Enter the number of kingdoms: ";
	cin >> count;
	cin.ignore();

	if (count < 1) return 1;
	pKingdom = new Kingdom[count];
	// allocated dynamic memory here for the pKingdom pointer

	for (int i = 0; i < count; ++i) {
		cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]);
		//  accept user input for Kingdom i
	}
	cout << "==========" << endl << endl;

	// testing that "display(...)" works
	cout << "------------------------------" << endl
		<< "The first kingdom entered is" << endl
		<< "------------------------------" << endl;
	display(pKingdom[0]);
	cout << "------------------------------" << endl << endl;
//allocating dynamic memory for count+1 kingdoms
	Kingdom* pKingdom2 = nullptr;
//copying the address of new array into the original one
	pKingdom2 = new Kingdom[count + 1];
//copying elemsnts of original array into new array.
	
	pKingdom2[0] = pKingdom[0];
	pKingdom2[1] = pKingdom[1];
	//deallocating the dynamic memory for original array
	
	delete[] pKingdom;
	pKingdom = new Kingdom[count + 1];
	pKingdom = pKingdom2;
	

	// add the new Kingdom
	cout << "==========\n"
		<< "Input data\n"
		<< "==========\n"
		<< "Kingdom #" << count + 1 << ": " << endl;
	read(pKingdom[count]);
	
	// accept input for the new element in the array
	count++;
	cout << "==========\n" << endl;

	

 // testing that the overload of "display(...)" works
display(pKingdom, count);
cout << endl;

//  deallocate the dynamic memory here
delete[] pKingdom;

return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {

cout << "Enter the name of the kingdom: ";
cin.get(kingdom.m_name, 32, '\n');
cin.ignore(2000, '\n');
cout << "Enter the number people living in " << kingdom.m_name << ": ";
cin >> kingdom.m_population;
cin.ignore(2000, '\n');
}
