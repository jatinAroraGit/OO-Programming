/***********************************************************
Workshop 8: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 7/24/17
FILE - CheckingAccount.cpp


// PURPOSE - this file includes class CheckingAccount definition along with its member functions
*******************************************************************/
//header
#include "CheckingAccount.h"

using namespace std;
//namespace block
namespace ict{    
	CheckingAccount::CheckingAccount() {
		transactionFee = 0;
	}
	
	//constructor to intialize data members with user input
	CheckingAccount::CheckingAccount(double newBal, double trFees)
	{
		double bal = getBalance();
		double sum = bal + newBal;
		
		setBalance(sum);
		if (trFees < 0)
			transactionFee = 0;
		else {
			transactionFee = trFees;
			newBal -= trFees;
		}
		
	}
	//charge fee() function defintion
	double CheckingAccount::chargeFee()
	{
		double bal = getBalance();
		double newBal = bal - transactionFee;
		
		setBalance(newBal);
		
		return newBal;
	}
	//debit() funtion defintion
	bool CheckingAccount::debit(double AMT)
	{
		double newBal;
		bool chk = Account::debit(AMT);
		if (chk == true)
		{
			if (getBalance() > transactionFee)
				newBal = (getBalance()) - transactionFee;
			setBalance(newBal);
			return true;
		}
		return false;

	}
	//credit() function defintion
	void CheckingAccount::credit(double amt)
	{
		double newBal;

		if (getBalance() > transactionFee)
		{
			newBal = (getBalance())+amt - transactionFee;
			setBalance(newBal);

		}
	}
	//display function defintion
	void CheckingAccount::display(std::ostream & ostr)
	{
		ostr << "Account type: Checking" << endl;
		ostr.setf(ios::fixed);
		ostr.precision(2);
		ostr << "Balance: $ " << getBalance() << endl;
		ostr << "Transaction Fee: " << transactionFee << endl;
	}

}
