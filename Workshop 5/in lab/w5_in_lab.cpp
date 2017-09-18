
/*********************************************************************
Workshop 5: LAB
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/15/17
FILE - w5_in_lab.cpp


// PURPOSE - tis file includes main function where the purpose of this code is implemented
*******************************************************************/
///headers
#include <iostream>
#include "Fraction.h"
//namespaces
using namespace std;
using namespace sict;

int main() {
	cout << "------------------------------" << endl;
	cout << "Fraction Class Test:" << endl;
	cout << "------------------------------" << endl;

	sict::Fraction a;
	cout << "Fraction a; // ";
	cout << "a = ";
	a.display();
	cout << endl;

	Fraction b(1, 3);
	cout << "Fraction b(1, 3); // ";
	cout << "b = ";
	b.display();
	cout << endl;

	Fraction c(-5, 15);
	cout << "Fraction c(-5, 15); //";
	cout << " c = ";
	c.display();
	cout << endl;

	Fraction d(2, 4);
	cout << "Fraction d(2, 4); //";
	cout << " d = ";
	d.display();
	cout << endl;

	Fraction e(8, 4);
	cout << "Fraction e(8, 4); //";
	cout << " e = ";
	e.display();
	cout << endl;

	cout << "a + b equals ";
	(a + b).display();
	cout << endl;

	cout << "b + d equals ";
	(b + d).display();
	cout << endl;

	return 0;
}
