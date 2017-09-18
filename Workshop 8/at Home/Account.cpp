/***********************************************************
Workshop 8: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 7/24/17
FILE - Account.cpp


// PURPOSE - this file includes defintion of member functions of class Account
*******************************************************************/

//headers
#include <iostream>
#include <fstream>
#include <cstring>
#include "Account.h"

using namespace std;
//namespace block
namespace ict {
	//default constructor
	Account::Account()
	{
		balance = 0.0;
	}
	//constructor to intialize data members with user input
	Account::Account(double bal)
	{
		if (bal > 0)
			balance = bal;
		else
			balance = 1.0;
	}
	//credit function defintion
	void Account::credit(double cre)
	{
		balance = balance + cre;
	}
	//debit funtion defintion
	bool Account::debit(double deb)
	{
		if (deb < balance) {
			balance = balance - deb;
			return true;
		}
		else if (balance < deb)
			return false;
return false;
	}
	//getBalance function defintion
	double Account::getBalance() const
	{
		return balance;
	}
	//setBalance funtion definiton
	void Account::setBalance(double newBalance)
	{
		balance = newBalance;
	}

}
