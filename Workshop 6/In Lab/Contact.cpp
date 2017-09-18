/***********************************************************
Workshop 6: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/22/17
FILE - Contact.cpp

// PURPOSE - tis file includes definitons of member functions of the class and two constructors and one destrucutor.
*******************************************************************/
//headers
#include <iostream>
#include "Contact.h"
#include <cstring>
using namespace std;
//namespace block
namespace sict {
	//default constructor
	Contact::Contact() {
		name[0] = '\0';
		phn = 0;
		Nphn = -1;
	}
	//constructor with 3 parameters
	Contact::Contact(const char* nm, const long long* num, const int n) {
		 
		
		if (nm != nullptr) {
			strncpy(name, nm, L);
			name[L-1] = '\0';
			int i;
			int s = 0;
			if (num != nullptr) {
				for (i = 0; i < n; i++) {
					if (num[i] > 10000000000 && num[i] < 999999999999) {
						s = s + 1;
					}
				}
				Nphn = s;
				phn = new long long[s];
				int b = 0;
				for (i = 0; i < n; i++) {
					if (num[i] > 10000000000 && num[i] < 999999999999) {
						phn[b] = num[i];
						b++;
					}
				}
			}
			else {
				Nphn = -1;
				phn = 0;
			}
		}
		else {
			name[0] = '\0';
			phn = 0;
			Nphn = -1;
		}
	}
	//destructor
	Contact::~Contact() {
		delete [] phn;
		phn = 0;
	}
	//definiton of display function
	void Contact::display() const {
		
		if (name != nullptr && name[0] != '\0' && name[0] != 0) {
			int len = L - 2;
			for (int i = 0; i <len; i++) {
			if(name[i]!='\0'|| name[i]!=0)	
				cout << name[i];
			}
			cout << endl;
			if (Nphn != -1 && phn != 0) {
				int i;
				for (i = 0; i < Nphn; i++) {
					long long N = phn[i];
					int a, b, n;
					int rem[12] = { 0 };
					n = 0;
					a = 0;
					while (N > 0) {
						rem[n] = N % 10;
						N = N / 10;
						n = n + 1;
					}
					a = 11;
					if (n > 11) {
						cout << "(+" << rem[a] << rem[10] << ") ";
						for (b = 9; b > 6; b--) {
							cout << rem[b];
						}
						cout << " ";
						for (b = 6; b > 3; b--) {
							cout << rem[b];
						}
						cout << "-";
						for (b = 3; b >= 0; b--) {
							cout << rem[b];
						}
						cout << endl;
					}
					else {
						cout << "(+" << rem[10] << ") ";
						for (b = 9; b > 6; b--) {
							cout << rem[b];
						}
						cout << " ";
						for (b = 6; b > 3; b--) {
							cout << rem[b];
						}
						cout << "-";
						for (b = 3; b >= 0; b--) {
							cout << rem[b];
						}
						cout << endl;
					}
				}
			}
			else if (name == nullptr && phn == nullptr)
				cout << "Empty contact!" << endl;

		}
		else
			cout << "Empty contact!" << endl;
		
	}
	//definiton of isEmpty function
	bool Contact::isEmpty() const {
		return name == 0;
	}
}//namespace close
