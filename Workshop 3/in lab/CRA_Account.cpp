/***********************************************************
Workshop 3: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________ |
!#^*(&!^@


// PURPOSE - tis file includes definitons of member functions of the class
*******************************************************************/

#include <iostream>
#include <string.h>
using namespace std;
#include "CRA_Account.h"
namespace sict {
	//definiton of set function
	void CRA_Account::set(const char * familyName, const char * givenName, int sin)
	{
		sin_number = sin;
		bool result = isValid();
		if (result)
		{
			strcpy(famnm, familyName);
			strcpy(accnm, givenName);
			
		}
		else
		{
			strcpy(famnm, "");
			strcpy(accnm, "");
			sin_number = 0;
			
		}
	}
	//definiton of isValid function
	bool CRA_Account::isValid() const
	{
		
		if (sin_number>MIN_SIN&& sin_number<MAX_SIN) {
			
			return true;
		}
		else
		{
			
			return false;
		}
		
	};

	//definiton of display function
	void CRA_Account::display() const
	{
		if (sin_number != 0)
		{

			cout << "Family Name: " << famnm << endl;
			cout << "Given Name : " << accnm << endl;
			cout << "CRA Account: " << sin_number << endl;
		}
		else{
if(sin_number==0){

			cout << "Account object is empty!"<< endl;
	}
}
}
}
