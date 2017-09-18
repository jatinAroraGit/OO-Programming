/***********************************************************
Workshop 6: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/27/17
FILE - w6_at_home.cpp

// PURPOSE - it has the main function and tests  the code implemented in Contact.cpp file
*******************************************************************/
#include <iostream>
#include "Contact.h"

using namespace std;
using namespace sict;

int main() {
	sict::Contact theContact("John Doe", nullptr, 0); // sict:: intentional
	theContact.display();
	theContact += 14161234567LL;
	theContact += 14162345678LL;
	theContact += 14163456789LL;
	theContact += 114164567890LL;
	theContact.display();

	cout << endl << "Testing! Please wait:" << endl;

	for (int i = 1; i <= 5000000; i++)
	{
		Contact temp = theContact;
		theContact = temp;
		theContact = theContact;
		if (!(i % 10000))
			cout << ".";
		if (!(i % 500000))
			cout << endl;
	}
	cout << endl;
	theContact.display();

	return 0;
}
