
/* //////////////// Workshop 1 /////  AT HOME  //////////////
Name - JATIN ARORA
136897162

Purpose of Workshop - To make header files and use them in source code files
to get a desired output

Purpose of this file - it defines the functions which are contained in the "tools.h" file.
/////////////////////////////////////////////// */



#include<iostream>
using namespace std;
namespace sict{
	int getInt(int min, int max) {                         // Performs a full-proof integer entry

		int val;
		bool done = false;
		while (!done) {
			cin >> val;
			if (cin.fail()) {
				cin.clear();
				cout << "Invalid Integer, try again: ";
			}
			else {
				if (val < min || val > max) {
					cout << "Invalid value!" << endl << "Enter a value between " << min << " and " << max << ": ";
				}
				else {
					done = true;
				}
			}
			cin.ignore(1000, '\n');
		}
		return val;
	}
	int menu() {
		cout << "1- Number of Samples" << endl;
		cout << "2- Sample Entry" << endl;
		cout << "3- Draw Graph" << endl;
		cout << "0- Exit" << endl;
		cout << "> ";
		return getInt(0, 3);
	}
}
