/***********************************************************
Workshop 6: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/27/17
FILE - Contact.cpp

// PURPOSE - this file includes definiton of member functions of the class and two constructors and one destrucutor and 
another copy constructor which were declared in header file Constact.h.
*******************************************************************/
#include <iostream>
#include "Contact.h"
#include <cstring>
using namespace std;
//namespace block
namespace sict {
	//constructor initializing data members
	Contact::Contact() {
		name[0] = '\0';
		phn = 0;
		Nphn = -1;
	}
	//constructor with 3 arguments to validate input and assign values
	Contact::Contact(const char* nm, const long long* num, const int n) {
		if (name != nullptr) {
			strncpy(name, nm, 20);
			name[L] = '\0';
			int i;
			int sze = 0;
			if (n > 0) {
				for (i = 0; i < n; i++) {
					if (num[i] > 10000000000 && num[i] < 999999999999) {
						sze = sze + 1;
					}
				}
				Nphn = sze;
				phn = new long long[sze];
				int j = 0;
				for (i = 0; i < n; i++) {
					if (num[i] > 10000000000 && num[i] < 999999999999) {
						phn[j] = num[i];
						j++;
					}
				}
			}
			else if (n == 0) {
				Nphn = 0;
				phn = nullptr;
			}
			else {
				Nphn = -1;
				phn = 0;
			}
		}
		else {
			name[0] ='\0';
			phn = 0;
			Nphn = -1;
		}
	}
	//destructor
	Contact::~Contact() {
		delete[] phn;
		phn = 0;
	}
	//display function definiton
	void Contact::display() const {

		if (name != nullptr && name[0] != '\0' && name[0] != 0) {
			int len = L - 2;
			for (int i = 0; i <len; i++) {
				if (name[i] != '\0' || name[i] != 0)
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

	
	//isEmpty function definiton
	bool Contact::isEmpty() const {
		return name == 0;
	}
	//copy constructor definiton
	Contact::Contact(const Contact& copy) {
bool r= strcmp(this->name, copy.name);	
	if (r != 0) {
			strncpy(this->name, copy.name, 20);
			this->name[L] = '\0';
			this->Nphn = copy.Nphn;
			this->phn = new long long[copy.Nphn];
			int i;
			for (i = 0; i < copy.Nphn; i++) {
				this->phn[i] = copy.phn[i];
			}
		}
	}
	//copy assignmnet operator function definiton
	Contact& Contact::operator=(const Contact& copy) {
		if (strcmp(this->name, copy.name) != 0) {
			strncpy(this->name, copy.name, 20);
			this->name[L] = '\0';
			this->Nphn = copy.Nphn;
			delete[] this->phn;
			this->phn = new long long[this->Nphn];
			int i;
			for (i = 0; i < copy.Nphn; i++) {
				this->phn[i] = copy.phn[i];
			}
		}
		return *this;
	}
	//overloaded += operator function to add new numbers if valid
	Contact& Contact::operator+=(long long phoneNumber) {
		Contact CC;
		int i;
		if (this->Nphn == 0) {
			this->Nphn += 1;
			this->phn = new long long[this->Nphn];
			this->phn[0] = phoneNumber;
		}
		else {
			CC.phn = new long long[this->Nphn];
			for (i = 0; i < this->Nphn; i++) {
				CC.phn[i] = this->phn[i];
			}
			this->Nphn += 1;
			delete[] this->phn;
			this->phn = new long long[this->Nphn];
			for (i = 0; i < this->Nphn - 1; i++) {
				this->phn[i] = CC.phn[i];
			}
			this->phn[i] = phoneNumber;
		}
		return *this;
	}
}//namespace close
