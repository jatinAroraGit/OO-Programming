/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//Final Project Milestone 5
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/28/2017
// FILE - AmaPerishable.h

// Purpose - This file containts declaration of  member functions and non member functions of class AmaPerishable which is derived from AmaProduct class
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//guards
#ifndef SICT_AmaPerishable_H__
#define SICT_AmaPerishable_H__
//heeaders
#include<iostream>
#include "Date.h"
#include "AmaProduct.h"
#include "ErrorMessage.h"
using namespace sict;
using namespace std;
//namespace block
namespace sict {
//derived class declaration
	class AmaPerishable : public AmaProduct {
	//data member
			Date expiry_;
//public member function
	public:
//constructor defintion
		AmaPerishable() :AmaProduct::AmaProduct('P') {
		};
		const Date& expiry()const;
		void expiry(const Date &value);
		//functions
		std::fstream& store(std::fstream& file,bool addNewLine=false ) const;
		std::fstream& load(std::fstream& file);
		std::ostream& write(std::ostream& os, bool linear) const;
		std::istream& read(std::istream& is);

		
	};

}

#endif
