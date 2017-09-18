/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//Final Project Milestone 1
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/07/2017
// FILE - Date.cpp

// Purpose - This file containts definitons of several member functionsa and constructors along with some non member operators
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//headers
#include "Date.h"
#include "general.h"
#include <iostream>
#include <cstring>
using namespace std;
//namespace block
namespace sict {
	//define value function //pre-provided
	int Date::value()const {
		return year_ * 372 + mon_ * 31 + day_;
	}
//	errCode()function dedinition
	void Date::errCode(int errorCode)
	{
		readErrorCode_ = errorCode;
	}
	//constructor tio initialize data members
	Date::Date()
	{
		
		year_ = 00;
		mon_ = 00;
		day_ = 0;
		readErrorCode_ = NO_ERROR;
	}
	//constructor with 3 arguments
	Date::Date(int y, int m, int d)
	{
		year_ = y;
		mon_ = m;
		day_ = d;
		readErrorCode_ = NO_ERROR;
	}
	
	//mdays function definition was already provided
	int Date::mdays()const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
		mon--;
		return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
	}
	//logical operator overload starts
	//operator== overload definition
	bool Date::operator==(const Date& D) const {
		return this->value() == D.value();
	}
	//operator!= overload definition
	bool Date::operator!=(const Date& D) const {
		return this->value() != D.value();
	}
	//operator< overload definition
	bool Date::operator<(const Date& D) const {
		return this->value() < D.value();
	}
	//operator> overload definition
	bool Date::operator>(const Date& D) const {
		return this->value() > D.value();
	}
	//operator<= overload definition
	bool Date::operator<=(const Date& D) const {
		return this->value() <= D.value();
	}
	//operator>= overload definition
	bool Date::operator>=(const Date& D) const {
		return this->value() >= D.value();
	}
	//Input member function definition
	std::istream& Date::read(std::istream& istr) {
		// setting everything to empty state
		year_ = 0;
		mon_ = 0;
		day_ = 0;
		errCode(NO_ERROR);
		int chk;        //for integers
		char chk2;      //for characaters like '/'
		
		// adds chk to input stream
		istr >> chk;
		// I am using fail() function of IO stream to easily detect successful input
		if ( !istr.fail()) {
			//if successul assign values
			
			year_ = chk;
		
		}
		else {
			//if nnot successful display error
			errCode(CIN_FAILED);
		}
		istr >> chk2;
		// adds character in chk2 to input stream
		if ( istr.fail()) {
			//if it is not "/" then input fails
			errCode(CIN_FAILED);
		}
		istr >> chk;
		if (!istr.fail()) {
			mon_ = chk;
		} 
		else {
			errCode(CIN_FAILED);
		}
		istr >> chk2;
		if ( istr.fail()) {
			errCode(CIN_FAILED);
		}
		istr >> chk;
		if (!istr.fail()) {
			
			day_ = chk;
		}
		else {
			errCode(CIN_FAILED);
		}
		//if all inputs are successful , check that values are in provided range
		if (!bad()) {
			{
				if (year_ < MIN_YEAR || year_ > MAX_YEAR) {
				errCode(YEAR_ERROR);
			}
			if (mon_ < 1 || mon_ > 12) {
				errCode(MON_ERROR);
				
			}
			else if (day_ < 1 || day_ > mdays()) {
				errCode(DAY_ERROR);
			}
		}
		}
	
		return istr;
	}
	//output member function definition
	std::ostream& Date::write(std::ostream& ostr) const {
		ostr.fill('0');
		ostr.width(1);
		ostr << year_ << "/";
		ostr.fill('0');
		ostr.width(2);
		ostr << mon_ << "/";
		ostr.fill('0');
		ostr.width(2);
		ostr << day_;
		return ostr;
	}

	/// errCode() definition
	int Date::errCode() const
	{
		return readErrorCode_;
	}
	// bad function returns true if error code is not equal to NO_ERROR
	bool Date::bad() const {
		return readErrorCode_ != NO_ERROR;


	}
	// output NON-MEMBER overload
	std::ostream& operator<<(std::ostream& out, const Date& dt ) {
		return dt.write(out);
	}
	// input NON-MEMBER overload
	std::istream& operator>>(std::istream& in, Date& dt) {
		return dt.read(in);
	}
}///namespace close
