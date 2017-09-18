/***********************************************************
Workshop 5: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/20/17
FILE - Fraction.h


// PURPOSE - tis file includes declaration of class and its member functions.
*******************************************************************/


//guards
#ifndef SCIT_FRACTION_H__
#define SCIT_FRACTION_H__
//namespace block
namespace sict {

	class Fraction {
		int denominator, numerator;
		int gcd() const; // returns the greatest common divisor of num and denom
		int max() const; // returns the maximum of num and denom
		int min() const; // returns the minimum of num and denom
		void reduce();   // simplifies a Fraction by dividing the 
						 // numerator and denominator to their greatest common divisor 
	public:
		//member functions
		//default constructor
		Fraction();
		//constructor to set values of n and d
		Fraction(int n, int d);
		void display() const;
		bool isEmpty() const;
		//overloaded member operators
		Fraction operator+(const Fraction& F) const;
		Fraction operator*(const Fraction&);
		bool operator==(const Fraction& F)const;
		bool operator!=(const Fraction& F)const;
		Fraction operator+=(const Fraction&);


	};//class close		
}//namespace close
#endif
