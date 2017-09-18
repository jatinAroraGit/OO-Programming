///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Final Project Milestone 2
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/10/2017
// FILE - ErrorMessage.h

// Purpose - This file contains declaration of several member functionsa and constructors along with a non member operators
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#ifndef SICT_ErrorMessage_H__
#define SICT_ErrorMessage_H__


#include<iostream>
using namespace std;
//namespace block
namespace sict {
//class declaration
	class ErrorMessage {
	//private data member
		char* message_;
	//public member function declaration
	public:
	    //constructors
		ErrorMessage();
		ErrorMessage(const char* errorMessage);
		ErrorMessage(const ErrorMessage& em)=delete;
		//----------------------------------------------------//
		//operator functions
		ErrorMessage& operator=(const ErrorMessage& em)=delete;
		ErrorMessage& operator=(const char* errorMessage);
		operator bool() const;
		//----------------------------------------------------//
		//destructor
		virtual ~ErrorMessage();
		//other member function defintion
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message()const;
		
	};
	//helper operator<< function declaration
	std::ostream& operator<<(std::ostream& os, const ErrorMessage& obj);
}
#endif
