///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Final Project Milestone 2
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/10/2017
// FILE - ErrorMessage.cpp

// Purpose - This file containts definitons of several member functionsa and constructors along with some non member operators
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//headers
#include<iostream>
#include<cstring>
#include "ErrorMessage.h"
using namespace std;
 
#define _CRT_SECURE_NO_WARNINGS
namespace sict {
	//default constructor
	ErrorMessage::ErrorMessage()
	{
		message_ = nullptr;
	}
//constructor with a parameter
	ErrorMessage::ErrorMessage(const char * errorMessage)
	{
		message_ = nullptr;
		message(errorMessage);
	}

	
	//copy assiginment operator

	ErrorMessage & ErrorMessage::operator=(const char * errorMessage)
	{
//to clear exisitng values
		clear();
				
			message(errorMessage);
		
		return *this;
	}
//destructor
	ErrorMessage::~ErrorMessage()
	{
		clear();
		
	}
// clear() function definiton to deallocate memory and assign nullptr to message_
	void ErrorMessage::clear()
	{
		
		delete[] message_;
		message_ = nullptr;
	}
//isClear() function definiton. Return strue if it is in safe empty state.
	bool ErrorMessage::isClear() const
	{
		return message_==nullptr;

	}
	//messge(char * value definiton)
	void ErrorMessage::message(const char * value)
	{
		
		delete[] message_;
		
		int s = strlen(value);
			
			
			message_ = new char[s+1];
			strcpy(message_, value);
		
		

	}
//message() function definiton
	const  char* ErrorMessage::message() const
	{
		
			return message_;
			
		
}
//operator<< defintion which is responsible for output on screen
	std::ostream& operator<<(std::ostream& os, const ErrorMessage& obj) {   // prints the ErrorMessage object using ostream
		
		 
		if (obj.ErrorMessage::isClear())
		{
			return os;
		}
		else
		{
			int s = strlen(obj.message());
			const char* msg = obj.message();
			for (int i = 0; i < s; i++)
			{
				os << msg[i];
			}
			return os;
		}
	}
	}


