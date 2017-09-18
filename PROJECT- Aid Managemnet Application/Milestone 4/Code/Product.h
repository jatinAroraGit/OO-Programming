// Final Project Milestone 4
// Version 1.0
// Date	2017-07-12
// Author	
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////
#ifndef SICT_PRODUCT_H
#define SICT_PRODUCT_H
#include <iostream>
#include <fstream>
#include "general.h"
#include "Streamable.h"

namespace sict {
class Product : public Streamable{
   private:
       char sku_[MAX_SKU_LEN+1];
       char* name_;
       double price_;
       bool taxed_;
       int quantity_;
       int qtyNeeded_;
   public:
       Product();
       Product(const char* SKU, const char* nm, bool tax=true, double p=0, int qtyNeed=0);

       Product(const Product&);
       const Product& operator=(const Product&);
       virtual ~Product(); 
       //setter
       void sku(const char*); 
       void name(const char*);
       void price(double);
       void taxed(bool);
       void quantity(int);
       void qtyNeeded(int); 
       
       //getter 
       const char* sku() const;
       double price() const;
       const char* name() const;
       bool taxed() const;
       int  quantity() const;
       int qtyNeeded() const;
       double cost() const;

       bool isEmpty() const;
       

       bool operator==(const char *) const;
       int operator+= (int); 
       int operator-= (int);

};
       double operator+= (double&, const Product&);
       std::ostream& operator <<(std::ostream& ostr, const Product& P);
       std::istream& operator >> (std::istream& istr, Product& P);
}

#endif
