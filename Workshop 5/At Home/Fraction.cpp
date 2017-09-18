/***********************************************************
Workshop 5: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/20/17
FILE - Fraction.cpp


// PURPOSE - tis file includes definion of member functions of class "Fraction".
*******************************************************************/


//headers
#include<iostream>
#include "Fraction.h"
using namespace std;
//namespace block
namespace sict {
	//default constructor
	Fraction::Fraction()
	{
		numerator = 0;
		denominator = -1;
	}
	// defining constructor to store values in n and d
	Fraction::Fraction(int n, int d)
	{
		if (n >= 0 && d > 0)
		{
			numerator = n;
			denominator = d;
			reduce();
		}
		else
		{
			numerator = 0;
			denominator = -1;
		}
	}
	// max returns the maximum of the numerator and denominator
	int Fraction::max() const
	{
		//ternary operator returns max of numerator or denominator
		return (numerator >= denominator) ? numerator : denominator;

	}
	//min function return minimum of numerator adn denominator
	int Fraction::min() const
	{
		//ternary operator returns minimum of numerator or denominator
		return (numerator >= denominator) ? denominator : numerator;

	}

	// gcd returns the greatest common divisor of numerator and d

	int Fraction::gcd() const {
		int mn = min();  // min of numerator and denominator
		int mx = max();  // max of numerator and denominator
		int g_c_d = 1;
		bool found = false;

		for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
			if (mx % x == 0 && mn % x == 0) {
				found = true;
				g_c_d = x;
			}
		}
		return g_c_d;
	}

	//reduce function defined
	void Fraction::reduce() {
		int red = gcd();
		numerator /= red;
		denominator /= red;
	}
	// definiton of display function
	void Fraction::display() const
	{
		if (!isEmpty())
		{
			if (denominator == 1)
			{
				cout << numerator;
			}
			else
			{
				cout << numerator << "/" << denominator;
			}
		}
		else
		{
			cout << "no fraction stored";
		}
	}
	// implementation of isEmpty function
	bool Fraction::isEmpty() const
	{
		return numerator == -1 || denominator == -1;
	}

	//member opearator+ definition
	Fraction Fraction :: operator+(const Fraction & F) const
	{
		Fraction f;
		bool check = this->isEmpty();
		bool check2 = F.isEmpty();

		if (check != true && check2 != true)
		{
			void reduce();
			f.numerator = ((this->numerator * F.denominator) + (F.numerator * this->denominator));
			f.denominator = ((this->denominator * F.denominator));
		}
		return f;
	}
	//defining operator* function
	Fraction Fraction :: operator*(const Fraction& F2)
	{
		Fraction n;
		bool check = this->isEmpty();
		bool check2 = F2.isEmpty();
		if (check != true && check2 != true)
		{
			n.numerator = (this->numerator * F2.numerator);
			n.denominator = ((this->denominator* F2.denominator));
		}
		return n;
	}
	//defining operator== function
	bool Fraction::operator==(const Fraction & F) const
	{
		bool check = false;
		Fraction f1, f2;
		bool chkobj = this->isEmpty();
		bool current = F.isEmpty();

		if (chkobj != true && current != true)
		{
			f1.numerator = (this->numerator * F.denominator);
			f2.numerator = (this->denominator * F.numerator);

			if (f1.numerator == f2.numerator)
			{
				return true;
			}

			return check;

		}
		return false;
	}
	// defining operator!= function
	bool Fraction::operator!=(const Fraction & F) const
	{
		bool check = false;
		Fraction f1, f2;
		bool chkobj = this->isEmpty();
		bool current = F.isEmpty();

		if (chkobj != true && current != true)
		{
			f1.numerator = (this->numerator * F.denominator);
			f2.numerator = (this->denominator * F.numerator);

			if (f1.numerator != f2.numerator)
			{
				return true;
			}
		}
		return check;
		
	}
	//operator+= function definiton
	Fraction Fraction :: operator+=(const Fraction& F3)
	{
		
			if (this->isEmpty() != true && F3.isEmpty() != true) {

				this->numerator = ((this->numerator * F3.denominator) + (F3.numerator * this->denominator));
				this->denominator = (this->denominator * F3.denominator);

			}
			
			return *this;
		
	}
}//namespace close


