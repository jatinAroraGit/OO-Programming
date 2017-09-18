/***********************************************************
Workshop 8: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 07/20/17
FILE - Account.h

// PURPOSE - this file includes declaration of member functions of the class and two constructors along with member functions
*******************************************************************/


#ifndef ICT_ACCOUNT_H__
#define ICT_ACCOUNT_H__
//headers
#include <iostream>

using namespace std;
//namesoace block
namespace ict{
   //class declaration
	class Account{
		private:
			double balance;

		protected:
			double getBalance() const; 
			void setBalance( double ); 
//emeber functions
   		public:
		//constructors	
			Account();
			Account(double bal);
			 
			virtual void credit(double amt);
			virtual bool debit(double AMT);
			
		virtual void display(std::ostream& os)=0;
						
   };
}
#endif
