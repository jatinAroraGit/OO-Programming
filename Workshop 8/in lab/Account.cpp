
//headers
#include <iostream>
#include <fstream>
/***********************************************************
Workshop 8: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 07/20/17
FILE - Account.cpp

// PURPOSE - this file includes defintion of member functions of the class and two constructors along with member functions
*******************************************************************/


#include <cstring>
#include "Account.h"

using namespace std;
//namespace block
namespace ict{ 
	//default constructor
	Account::Account()
	{
		balance = 0.0;
	}
//constructor to set value of balance
	Account::Account(double bal)
	{
		if (bal > 0)
			balance = bal;
		else
			balance = 1.0;
	}
//credit function definition
	void Account::credit(double cre)
	{
		balance = balance+cre;
	}
//debit function defintition
	bool Account::debit(double deb)
	{
bool chk=false;
		if (deb < balance) {
			balance = balance - deb;
			chk= true;
		}
		else if (balance < deb)
			chk= false;

return chk;	
}
	//getbalance fiuntiuon defintion
	double Account::getBalance() const
	{
		return balance;
	} 
//setBalance function defintion
	void Account::setBalance( double newBalance )
	{
		balance = newBalance;
	}

}
