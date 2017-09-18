/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//Final Project Milestone 1
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/07/2017
// FILE - Date.h

// Purpose - This file containts declaration of several member functionsa and constructors along with some non member operators
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef SICT_DATE_H__
#define SICT_DATE_H__

#include <iostream>
namespace sict{
	//defining error codes
#define NO_ERROR   0 // No error the date is valid
#define CIN_FAILED 1 // istream failed when entering information
#define YEAR_ERROR 2 // Year value is invalid
#define MON_ERROR  3 // Month value is invalid
#define DAY_ERROR  4 // Day value is invalid

	//class declaration
   class Date {
  
	   int year_;
	   int mon_;
	   int day_;
	   int readErrorCode_;
      int value()const;
	  void errCode(int errorCode) const;
	  void errCode(int errorCode);
   public:
 //constructors
	   Date();
	   Date(int y, int m, int d);
	  //member functions
      int mdays()const;
	//logical operator overloads
	  bool operator==(const Date& D)const;
	  bool operator!=(const Date& D)const;
	  bool operator<(const Date& D)const;
	  bool operator>(const Date& D)const;
	  bool operator<=(const Date& D)const;
	  bool operator>=(const Date& D)const;

	  int errCode()const;
	  bool bad()const;
	  // IO member function
	  std::istream& read(std::istream& istr);
	  std::ostream& write(std::ostream& ostr)const;

   };

   // non member IO functions
   std::ostream& operator<<(std::ostream& os, const Date& D);
   std::istream& operator>>(std::istream& is, Date& D);

}//namespace close
#endif