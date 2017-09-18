/***********************************************************
Workshop 5: LAB
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/15/17
FILE - Fraction.cpp


// PURPOSE - tis file includes definitons of member functions of the class and two constructors.
*******************************************************************/

//headers
#include<iostream>
#include "Fraction.h"
using namespace std;
//namepsace block
namespace sict {
	//constructor to set variables to safe empty state
	Fraction::Fraction() {
		numerator = -1;
		denominator = -1;              
	}
       //constructor with 2 parameters. It only stores data if Valid.
	Fraction::Fraction(int n, int d) 
	{
		if (n >= 0 && d > 0) {
			numerator = n;
			denominator = d;
			reduce();
		}
		else
		{
			numerator = -1;
				denominator = -1;             
		}
	}
        //definion of gcd function (was already provided)
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
        //definiton of max function to return bigger of 2 numbers
	int Fraction::max() const
	{
		//ternary operator returns max of numerator or denominator
		return (numerator >= denominator) ? numerator : denominator;

	}
   //definiton of max function to return smaller of 2 numbers

	int Fraction::min() const
	{
		//ternary operator returns minimum of numerator or denominator
		return (numerator >= denominator) ? denominator : numerator;

	}
// definiton of reduce function
	void Fraction::reduce()                                         // simplify the Fraction number  
	{
		int r = gcd();
		numerator /= r;
		denominator /= r;
	}
//definiton of display function
	void Fraction::display() const {
		if (!isEmpty()) {
			if (denominator == 1) {
				cout << numerator;
			}
			else {
				cout << numerator << "/" << denominator;
			}
		}
		else {
			cout << "no fraction stored";
		}
	}

	// implementation of isEmpty function
	bool Fraction::isEmpty() const {
		return numerator == -1 || denominator == -1;
	}
//definiton of operator function
	Fraction Fraction:: operator+(const Fraction& F) {
		Fraction f;
		bool chkObj = F.isEmpty();
		bool check = this->isEmpty();

		if (check != true && chkObj != true) {
			f.numerator = ((this->numerator * F.denominator) + (F.numerator * this->denominator));
			f.denominator = (this->denominator * F.denominator);
		}
		return f;
	}
	} //namespace closed
