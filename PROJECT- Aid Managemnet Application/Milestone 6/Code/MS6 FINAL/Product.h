/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//Final Project Milestone 4
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/17/2017
// FILE - Product.h

// Purpose - This file containts declaration of a Class derived from Streamable class along with its member functions and nin member functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//guards
#ifndef SICT_PRODUCT_H_
#define SICT_PRODUCT_H_
//headers
#include "general.h"
#include "Streamable.h"

using namespace sict;
//namespace block
namespace sict {
	class Product : public Streamable {
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	public:
		//constructor
		Product();
		Product(const char* SKU, const char* nm, bool tax = true, double p = 0.0, int qtyNeed = 0);
		Product(const Product& cp);
		Product& operator=(const Product& obj);
		//destructor
		virtual ~Product();
		//setter functions
		void sku(const char* SKU);
		void price(double p);
		void name(const char* nm);
		void taxed(bool tax);
		void quantity(int qty);
		void qtyNeeded(int qtyNeed);
		//getters
		const char* sku() const;
		double price() const;
		const char* name() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		double cost() const;
		bool isEmpty() const;
		//operator member functions
		bool operator==(const char* SKU);
		int operator+=(int qty);
		int operator-=(int qty);
	};
	//nion-member functions
	double operator+=(double& L, const Product& P);
	std::ostream& operator<<(std::ostream& os, const Product& Pro);
	std::istream& operator>>(std::istream& is, Product& Pro);
}

#endif