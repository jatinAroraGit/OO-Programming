/***********************************************************
Workshop 8: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 07/20/17
FILE - SavingsAccount.h

// PURPOSE - this file includes declaration of member functions of the derived class and two constructors along with member functions
*******************************************************************/


#ifndef ICT_SAVINGSACCOUNT_H__
#define ICT_SAVINGSACCOUNT_H__
//headers
#include "Account.h"

using namespace std;
//namespace block
namespace ict{
//derived class
	class SavingsAccount : public Account{
		private:
    		double interestRate; // interest rate (percentage) 
		public:
//constructors	
		SavingsAccount();
			SavingsAccount(double bal, double rate);
			double calculateInterest();
			virtual void display(std::ostream& os);

   };
};
#endif
