// Final Project Milestone 4
// Version 1.0
// Date	2017-07-12
// Author	
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include "Product.h"
#include "general.h"
#include "Streamable.h"

using namespace std;

namespace sict {
    //constructor 1 : default
    Product::Product()
    {
        sku_[0]='\0';
        name_ = nullptr;
        price_= 0.0;
        taxed_=true;
        quantity_=0;
        qtyNeeded_=0;
    }

    //constructor 2 : parameter 5 (using setter function) 
    Product::Product(const char* SKU, const char* nm, bool tax, double p, int qtyNeed)
    {
            sku(SKU);
            //name_ = nullptr;
            name(nm);
            price(p);
            taxed(tax);
            quantity(0);
            qtyNeeded(qtyNeed);
    }

    //constructor 4 : copy constructor (using setter function) 
    Product::Product(const Product& product)
    {
        if ((product.isEmpty() == false) && (this!=&product))
        {
            sku(product.sku_);
            //name_ = nullptr;
            name(product.name_);
            price(product.price_);
            taxed(product.taxed_);
            quantity(product.quantity_);
            qtyNeeded(product.qtyNeeded_);
        }

    }
    
    //function 1 : assignment operator (using setter function)
    const Product& Product::operator=(const Product& product)
    {
        if ((this != &product) && (product.isEmpty() == false) )
        {
            sku(product.sku_);
            //name_ = nullptr;
            delete[] name_; 
            name(product.name_);
            price(product.price_);
            taxed(product.taxed_);
            quantity(product.quantity_);
            qtyNeeded(product.qtyNeeded_);
        }

        return *this;
    }
    
    //function 2 : setter
    void Product::sku(const char* sku)
    {
        if (sku != nullptr)
        {
            strncpy(sku_, sku, MAX_SKU_LEN);
            sku_[MAX_SKU_LEN] = '\0';
        }
        else
        {
            sku_[0] = '\0';
        }
    }

    void Product::price(double price)
    {
        price_ = price; 
    }

    void Product::name(const char* name)
    {

        if (name!=nullptr) 
        {   
            name_ = new char[strlen(name) + 1];
            strncpy(name_, name, strlen(name));
            name_[strlen(name)] = '\0';
        }
        else 
        {
            name_ = nullptr;
        }
        
    }

    void Product::taxed(bool taxed)
    {
        taxed_ = taxed;
    }

    void Product::quantity(int quantity)
    {
        quantity_ = quantity;
    }

    void Product::qtyNeeded(int qtyNeeded)
    {
        qtyNeeded_ = qtyNeeded;
    }

    //function 3 : getter(queries : do not modify) 
    const char* Product::sku() const
    {
        return sku_;
    }

    double Product::price() const
    {
        return price_; 
    }

    const char* Product::name() const
    {
        return name_;
    }

    bool Product::taxed() const
    {
        return taxed_;
    }

    int  Product::quantity() const
    {
        return quantity_;
    }

    int Product::qtyNeeded() const
    {
        return qtyNeeded_;
    }

	double Product::cost() const
	{
		double cost_ = 0.0;
		if (taxed_ == true)
		{
			cost_ = price() * (1 + TAX);
		}
		else
		{
			cost_ = price();
		}

		return cost_;
	}

    //function 4 : check the safety empty status 
    bool Product::isEmpty() const
    {   
        bool check;
        if ((sku_[0] == '\0')&& (name_ == nullptr) && (price_ == 0.0) && (quantity_ == 0) &&(qtyNeeded_ ==0))
        {
            check = true;
        }
        else
        {
            check = false;
        }
        return check; 
    }
    
    // destructor : deallocate dynamin memory 
    Product::~Product()
    {
        delete[] name_;
    }

    //function 5 : check the same sku 
    bool Product::operator==(const char * skui) const
    {    
		return strcmp(sku_, skui) == 0;
    }

    //function 6 : add quantity
    int Product::operator+= (int addqty)
    {
        int sum = 0;
        sum = quantity() + addqty;
        return sum; 
    }

    //function 7 : reduce quantity
    int Product::operator-= (int subqty)
    {
        int sum = 0;
        sum = quantity() - subqty;
        return sum; 
    }

    //function 8 : find total cost (tcost)
    double operator+= (double& tcost, const Product& product)
    {
        tcost = 0.0;
        tcost = tcost +(product.cost())*(product.quantity());
        return tcost; 
    }


    std::ostream& operator <<(std::ostream& ostr, const Product& P)
    {
        return P.write(ostr, true);
    }
    std::istream& operator >> (std::istream& istr, Product& P)
    {
        return P.read(istr);
    }
}
