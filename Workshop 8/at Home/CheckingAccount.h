/***********************************************************
Workshop 8: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 7/24/17
FILE - CheckingAccount.h


// PURPOSE - this file includes class CheckingAccount declaration along with its member functions
*******************************************************************/

//guards
#ifndef ICT_CHECKINGACCOUNT_H__
#define ICT_CHECKINGACCOUNT_H__
//header
#include "Account.h"

using namespace std;
//namcespace block
namespace ict{
	//derived class declaration
	class CheckingAccount : public Account {
		//private data member
			double transactionFee;

			
		//memeber functions
		public:
			//constructor
			CheckingAccount();
			
			CheckingAccount(double inBAL, double trFees);
			//functions
			double chargeFee();
			//virtual functions
		bool debit(double AMT);
			  void credit(double amt);
			  void display(std::ostream& os);
			
	};
}//namespace cloese
#endif
