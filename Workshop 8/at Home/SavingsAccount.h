/***********************************************************
Workshop 8: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 7/24/17
FILE - SavingsAccount.h


// PURPOSE - this file includes SavingsAccount class declaration and declaration of ots member functions
*******************************************************************/


#ifndef ICT_SAVINGSACCOUNT_H__
#define ICT_SAVINGSACCOUNT_H__
///headers
#include "Account.h"

using namespace std;
//namespace block
namespace ict {
	//derived class declaration
	class SavingsAccount : public Account {
	
		double interestRate; // interest rate (percentage) 
	//memebr fucntions
	public:
		//constructors
		SavingsAccount();
		SavingsAccount(double bal, double rate);
		double calculateInterest();
		 void display(std::ostream& os);

	};
};
#endif
