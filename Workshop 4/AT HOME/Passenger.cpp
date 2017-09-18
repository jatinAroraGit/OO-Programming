/***********************************************************
Workshop 4: HOME
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/13/17
FILE - Passenger.cpp


// PURPOSE - tis file includes definitons of member functions of the class and two constructors.
*******************************************************************/

//headers
#include <iostream>
#include <cstring>
#include "Passenger.h"

using namespace std;
//namespace block
namespace sict {
	// default constructor
	Passenger::Passenger() {
		pname[0] = '\0';
		pdestination[0] = '\0';
	}
	//constructor with 2 parameters
	Passenger::Passenger(const char* nm, const char* dstn) {
		if ((nm != nullptr && dstn != nullptr)) {
			strncpy(pname, nm, LENGTH);
			strncpy(pdestination, dstn, LENGTH);
		}
		else {
			pname[0] = '\0';
			pdestination[0] = '\0';
		}
	}
	//constructor with 3 parameters
	Passenger::Passenger(const char * nm, const char * dstn, const int y, const int m, const int d)
	{
		if ((nm != nullptr && dstn != nullptr && y >= 2017 && y <= 2020 && m >= 1 && m <= 12 && d >= 1 && d <= 31)) {
			strncpy(pname, nm, LENGTH);
                        pname[LENGTH-1]='\0';

			strncpy(pdestination, dstn, LENGTH);
                        pdestination[LENGTH-1]='\0';

			day = d;
			
			month = m;
			year = y;
			
		}
		else {
			pname[0] = '\0';
			pdestination[0] = '\0';
			day = 0;
			month = 0;
			year = 0;
		}

	}
	// query that returns the address of the name of the passenger.
	const char * Passenger::name() const
	{

		if (pname != nullptr)
			return pname;
		else
			return nullptr;
	}
	bool Passenger::canTravelWith(const Passenger& P) const {
		bool check;
		if (day == P.day && month == P.month
			&& year == P.year && strcmp(pdestination, P.pdestination) == 0) {
			check = true;
		}
		else {
			check = false;
		}
		return check;
	}

	// defining isEmpty() function
	bool Passenger::isEmpty() const {
		if (pname[0] == 0 || pdestination[0] == 0)
			return true;
		else
			return false;
	}

	//defining display() function
	void Passenger::display() const {
if(this->month<10){
		cout << "" << this->pname << " - " << this->pdestination <<" on "<< this->year <<"/0"<< this->month<<"/" <<this->day <<endl;
	}
else
 cout << "" << this->pname << " - " << this->pdestination <<" on "<< this->year <<"/"<< this->month<<"/"<<this->day <<endl;
}

}
