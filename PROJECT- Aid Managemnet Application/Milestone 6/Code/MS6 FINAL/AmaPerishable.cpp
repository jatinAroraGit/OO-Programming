/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//Final Project Milestone 5
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/28/2017
// FILE - AmaPerishable.cpp

// Purpose - This file containts definition of  member functions and non member functions of class AmaPerishable which is derived from AmaProduct class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//headers
#include<iostream>
#include<fstream>
using namespace std;
#include "AmaPerishable.h"
using namespace sict;
//namespace block
namespace sict {
	//expiry function definitio returns expiry_ value
	const Date & AmaPerishable::expiry() const
	{
		return expiry_;
	}
//expiry function defintion sets expiry_ value
	void AmaPerishable::expiry(const Date & value)
	{
		expiry_ = value;
	}
//store function definition
	std::fstream & AmaPerishable::store(std::fstream & file, bool addNewLine) const
	{
	
		AmaProduct::store(file,false);
		file << "," << expiry_ << endl;
		if((addNewLine==true))
file<<"\n";
		return file;
	}
//load function definition
	std::fstream & AmaPerishable::load(std::fstream & file)
	{
		AmaProduct::load(file);
		expiry_.read(file);
		file.ignore();
		return file;
	}
//write function definition
	std::ostream & AmaPerishable::write(std::ostream & ostr, bool linear) const
	{
		
		AmaProduct::write(ostr, linear);
		
		if (err_.isClear())
		{
if((linear==true))
			ostr<< expiry();
		
else if((linear==false))
ostr<<"\n"<<"Expiry date: "<<expiry();
		
	}
return ostr;
}
//read function definition
	std::istream & AmaPerishable::read(std::istream & istr)
	{
		cin.clear();
	
		AmaProduct::read(istr);
		if (err_.isClear()) {
		cin.ignore();
			Date dt;
			cout << "Expiry date (YYYY/MM/DD): ";
expiry(dt);
			istr >> dt;

			if (dt.bad()) {
				if (dt.errCode() == CIN_FAILED) {
					err_.message("Invalid Date Entry");
				}
				else if (dt.errCode() == YEAR_ERROR) {
					err_.message("Invalid Year in Date Entry");
				}
				else if (dt.errCode() == MON_ERROR) {
					err_.message("Invalid Month in Date Entry");
				}
				else if (dt.errCode() == DAY_ERROR) {
					err_.message("Invalid Day in Date Entry");
				}
				istr.setstate(ios::failbit);
			}
			else {
			 expiry(dt);
			}
		}
	
		return istr;
	}

}

