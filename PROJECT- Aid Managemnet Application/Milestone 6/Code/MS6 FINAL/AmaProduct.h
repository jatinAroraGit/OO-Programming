/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//Final Project Milestone 5
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/28/2017
// FILE - AmaProduct.h

// Purpose - This file containts defintion of  member functions and non member functions of AmaProduct class which is derived from Product class 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef SICT_AMAPRODUCT_H__
#define SICT_AMAPRODUCT_H__
using namespace std;
//headers
#include "ErrorMessage.h"
#include "Product.h"

using namespace std;
using namespace sict;
//namespace block
namespace sict {
	//derived class declaration
	class AmaProduct : public Product {
		char fileTag_;
		char unit_[11];
//protected data member
	protected:
		
		ErrorMessage err_;
//public member function
	public:
	//constructor
		AmaProduct(char tag='N');
		const char* unit()const;
		void unit(const char* value);
		//virtual functions
		virtual std::fstream& store(std::fstream& file, bool addNewLine=true) const;
		virtual std::fstream& load(std::fstream& file);
		virtual std::ostream& write(std::ostream& ostr, bool linear) const;
		virtual std::istream& read(std::istream& istr);

	};

}
#endif


