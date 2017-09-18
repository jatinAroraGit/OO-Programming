/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//Final Project Milestone 6
//
// NAME - JATIN ARORA (136897162)
// DATE - 09/06/2017
// FILE - AmaProduct.cpp

// Purpose - This file containts declaration  of  member functions of AidApp class 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//guards
#ifndef _AIDAPP_H__
#define _AIDAPP_H__
//headers
#include "AmaProduct.h"
#include "AmaPerishable.h"
using namespace sict;
namespace sict{
//class declaration
	class AidApp {
		char filename_[256];
		Product* product_[MAX_NO_RECS];
		fstream datafile_;
		int noOfProducts_;
//member functions
		public:
			AidApp(const char* filename);
			void pause()const;
			int menu();
			void loadRecs();
			void saveRecs();
			void listProducts()const;
			int SearchProducts(const char* sku)const;
			void addQty(const char* sku);
			void addProduct(bool isPerishable);
			int run();


};

}

#endif
