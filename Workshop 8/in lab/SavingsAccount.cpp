/***********************************************************
Workshop 8: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 07/20/17
FILE - SavingsAccount.cpp

// PURPOSE - this file includes defintion of member functions of the derived class and two constructors along with member functions
*******************************************************************/


//headers
#include <iostream>
#include <fstream>
#include <cstring>
#include "SavingsAccount.h"
#include "Account.h"
using namespace std;
//namespace block
namespace ict{
//constructors
	SavingsAccount::SavingsAccount()
	{
		interestRate = 0.0;
	}
//constructor to set values to input by user
	SavingsAccount::SavingsAccount(double bal, double rate)
	{
		setBalance(bal);
		if (rate < 0)
			interestRate = 0;
		else
			interestRate = rate;
	}
//calaculateInterest defintion
	double SavingsAccount::calculateInterest()
	{
		double val = getBalance();
		double cal = val*interestRate;
		return cal;
	}
//display functrion defintion
	void SavingsAccount::display(std::ostream & ostr)
	{
		ostr << "Account type: Saving" << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Balance: $ " << getBalance() << endl;
		ostr << "Interest Rate (%): " << interestRate * 100 << endl;
	}
	
}
