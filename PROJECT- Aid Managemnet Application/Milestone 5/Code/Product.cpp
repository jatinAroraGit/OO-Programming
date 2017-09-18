/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//Final Project Milestone 4
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/17/2017
// FILE - Product.cpp

// Purpose - This file containts defintion of  member functions and non member functions of class product 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
//headers
#include <iostream>
#include <cstring>
#include "Product.h"
#include "general.h"

namespace sict {
	//default constructor  to set wvwerything to safe empty state 
	Product::Product() {
		sku_[0] = '\0';
		name_ = nullptr;
		price_ = 0;
		taxed_ = true;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}
	//constructor with 5 argumnets to set values to values input by user
	Product::Product(const char* SKU, const char* nm, bool tax, double p, int qtyNeed) {
		sku(SKU);
		name(nm);
		taxed(tax);
		price(p);
		qtyNeeded(qtyNeed);
		quantity(0);
	}
	//copy constructor
	Product::Product(const Product& cp) {
		if (!(cp.isEmpty()) && (this != &cp)) {
			*this = cp;
		}
	}
	//destructor
	Product::~Product() {
		delete[] name_;
		name_ = nullptr;
	}
	//copy assignmnet operator defintion
	Product& Product::operator=(const Product& obj)
	{
		//checking for equality
		if (this != &obj && !(obj.isEmpty())) {
			sku(obj.sku_);
			name(obj.name_);
			taxed(obj.taxed_);
			price(obj.price_);
			quantity(obj.quantity_);
			qtyNeeded(obj.qtyNeeded_);
		}
		return *this;
	}
	/////////////////////////////////////////////////////
	//setter functions
	//to set SKU value
	void Product::sku(const char* SKU) {
		strncpy(sku_, SKU, MAX_SKU_LEN);
		sku_[MAX_SKU_LEN] = '\0';
	}
	//to set price value
	void Product::price(double p) {
		price_ = p;
	}
	//to set name value
	void Product::name(const char* nm) {
		int s = strlen(nm);
		name_ = new char[s + 1];
		strncpy(name_, nm, s);
		name_[s] = '\0';
	}
	//to set tax value
	void Product::taxed(bool tax) {
		taxed_ = tax;
	}
	//to set quantity value
	void Product::quantity(int qty) {
		quantity_ = qty;
	}
	//to set qunatity needed value
	void Product::qtyNeeded(int qtyNeed) {
		qtyNeeded_ = qtyNeed;
	}
	/////////////////////////////////////////
	//getter functions to return values
	//to return SKU value
	const char* Product::sku() const {
		return sku_;
	}
	//to return price value
	double Product::price() const {
		return price_;
	}
	//to return name value
	const char* Product::name() const {
		return name_;
	}
	//to return tax value
	bool Product::taxed() const {
		return taxed_;
	}
	//to return quantity value
	int Product::quantity() const {
		return quantity_;
	}
	//to return qunatity needed  value
	int Product::qtyNeeded() const {
		return qtyNeeded_;
	}
	//////////////////////////////////////
	//cost() function returns final cost 
	double Product::cost() const {
		double cost = price();

		if (taxed_) {
			cost = price() * (1 + TAX);
		}
		return cost;
	}
	//setEmpty() definiton checks if data is in empty state
	bool Product::isEmpty() const {
		if (sku_[0] == '\0' && name_ == nullptr && price_ == 0 && taxed_ == true && quantity_ == 0 && qtyNeeded_ == 0)
			return true;
		else
		return false;
	}
	//operator== function defined
	bool Product::operator==(const char* SKU) {
		return strcmp(sku_, SKU) == 0;
	}
	//operator+= function defined
	int Product::operator+=(int qty) {
		return quantity_ += qty;
	}
	//operator-= function defined
	int Product::operator-=(int qty) {
		return quantity_ -= qty;
		}
	// overloaded operator+= function defined
	double operator+=(double& COST, const Product& P) {
		return 	(COST += (P.cost() * P.quantity()));
	}
	//operator<< function definition
	std::ostream& operator<<(std::ostream& os, const Product& Pro) {
		return Pro.write(os, true);
	}
	//operator>> function definition
	std::istream& operator>>(std::istream& is, Product& Pro) {
		return Pro.read(is);
	}
}
