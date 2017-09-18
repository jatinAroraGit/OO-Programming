/***********************************************************
Workshop 8: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 7/24/17
FILE - SavingsAccount.cpp


// PURPOSE - this file includes definiton of SavingsAccount class and its member funtions
*******************************************************************/


//headers
#include <iostream>
#include <fstream>
#include <cstring>
#include "SavingsAccount.h"
#include "Account.h"
using namespace std;
//namespace
namespace ict {
	//default constructor
	SavingsAccount::SavingsAccount()
	{
		interestRate = 0.0;
	}
	//constructor to intialize data members with user input
	SavingsAccount::SavingsAccount(double bal, double rate)
	{
		setBalance(bal);
		if (rate < 0)
			interestRate = 0;
		else
			interestRate = rate;
	}
	//calculateInterest function definition
	double SavingsAccount::calculateInterest()
	{
		double val = getBalance();
		double cal = val*interestRate;
		return cal;
	}
	//display function defitnion
	void SavingsAccount::display(std::ostream & ostr)
	{
		ostr << "Account type: Saving" << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Balance: $ " << getBalance() << endl;
		ostr << "Interest Rate (%): " << interestRate * 100 << endl;
	}

}
