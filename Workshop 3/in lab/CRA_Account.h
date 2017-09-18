/***********************************************************
Workshop 3: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________ |
!#^*(&!^@


	// PURPOSE - contains class declaration whih=ch is private by default and has some public functions which are declared in this file.These functions are display(), isValid() and set(); 
*******************************************************************/

//guards
#ifndef SICT_CRA_ACCOUNT_H               
#define SICT_CRA_ACCOUNT_H               
//namespace block
namespace sict {   
//defining
#define SICT_CRA_ACCOUNT_H
#define MAX_NAME_LENGTH 40
#define MIN_SIN 100000000
#define MAX_SIN 999999999
//class declaration
	class CRA_Account {
		char famnm[MAX_NAME_LENGTH];
		char accnm[MAX_NAME_LENGTH];
		int sin_number;
	public:
		//public member functions of the class
		//to modify private data members of the class
		void set(const char* familyName, const char* givenName, int sin);
		//to check validity of SIN number
		bool isValid() const;
		//to display informarion stored.
		void display() const;

	};
}
#endif
