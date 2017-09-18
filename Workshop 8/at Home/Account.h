/***********************************************************
Workshop 8: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 7/24/17
FILE - Account.h


// PURPOSE - this file includes base Class Account declaration and declaration of its member functions
*******************************************************************/
//guards
#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__
//headers
#include <iostream>

using namespace std;
//namespace block
namespace ict {
	//class decleration
	class Account {
//data members
		double balance; // data member that stores the balance

	protected:
		double getBalance() const; // return the account balance
		void setBalance(double); // sets the account balance

	public:
		//constructor
		Account();
		Account(double bal);
		//virtual functions 
		virtual void credit(double amt);
		virtual bool debit(double AMT);
		
		virtual void display(std::ostream& os) = 0;
				
	};
}
#endif
