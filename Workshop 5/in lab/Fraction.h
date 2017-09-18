/***********************************************************
Workshop 5: LAB
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/15/17
FILE - Fraction.h


// PURPOSE - tis file includes declaration of class and its  member functions and two constructors.
*******************************************************************/

#ifndef SICT_Fraction_H
#define SICT_Fraction_H

#include <iostream>
using namespace std;
//namespace block
namespace sict {
        //class declaration
	class Fraction {
		int denominator, numerator;
		int gcd() const; 
		int max() const; 
		int min() const; 
		void reduce();    
	//public member functions of class declared			 
	public:
        //constructors
	Fraction();     
    	Fraction(int n, int d );
	void display() const;

	bool isEmpty() const;
        //operator overloaded
	Fraction operator+(const Fraction& F);

	
	};
}
#endif
