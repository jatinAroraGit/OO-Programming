/***********************************************************
// OOP244 Workshop 2: Dynamic Memory
// File w2_in_lab.cpp
// Version 1.0
// Date ???????????
// Author ?????????
// Description
***********************************************************
Workshop 2: LAB
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
    !#^*(&!^@

// PURPOSE - this file is where the program comes together. The ain function inputs data which it stores in Kingdom structure pointer and then displays.
****************************************************************/


#include <iostream>
#include "Kingdom.h"

using namespace std;
//using namespace to access functions and structures
using namespace SICT;        

void read(Kingdom&);

int main() {
    int count = 0; // the number of kingdoms in the array
 Kingdom* pKingdom=nullptr;
    // declared the pKingdom pointer here

    cout << "==========\n"
         << "Input data\n"
         << "==========\n"
         << "Enter the number of kingdoms: ";
    cin >> count;
    cin.ignore();
	
    if (count < 1) return 1;
	 pKingdom= new Kingdom[count];
    // allocated dynamic memory here for the pKingdom pointer

    for (int i = 0; i < count; ++i) {
        cout << "Kingdom #" << i + 1 << ": " << endl;
		read(pKingdom[i]);               //calling read function
		
        // code to accept user input for Kingdom i
    }
    cout << "==========" << endl << endl;

    // testing that "display(...)" works
    cout << "------------------------------" << endl
        << "The first kingdom entered is" << endl
        << "------------------------------" << endl;
    display(pKingdom[0]);
    cout << "------------------------------" << endl << endl;
	delete[] pKingdom;
    //deallocating the dynamic memory here

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
