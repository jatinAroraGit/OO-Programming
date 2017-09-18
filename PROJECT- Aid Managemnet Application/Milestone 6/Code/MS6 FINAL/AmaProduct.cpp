/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//Final Project Milestone 5
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/28/2017
// FILE - AmaProduct.cpp

// Purpose - This file containts defintion of  member functions and non member functions of AmaProduct class which is derived from Product class 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//headers
#include "AmaProduct.h"
#include<iostream>
#include <cstring>
#include<string>
#include <iomanip>
#include <limits>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS
//namespace block
namespace sict {
//constructor to to initalize to user input
	sict::AmaProduct::AmaProduct(char tag)
	{
		fileTag_ = tag;
	}
//unit function defintion returns unit_ value
	const char * sict::AmaProduct::unit() const
	{
		return unit_;
	}
//unit function defintion sets unit_ value
	void sict::AmaProduct::unit(const char * value)
	{
		strncpy(unit_, value, 10);
		unit_[10] = '\0';
	}
//store function is used to store into file using fstream
	fstream& AmaProduct::store(fstream& file, bool addNewLine) const {
		
		file << fileTag_ << ',' << sku() << ',' << name() <<','<< price()<< ',' <<taxed()<< ',' << quantity() << ',' << unit() << ',' << qtyNeeded() ;
	if((addNewLine==true))
file<<"\n";
		return file;
	}
//load function is used to get data from file
	fstream& AmaProduct::load(fstream& file) {
		char s[MAX_TMPS_LEN];
		char n[MAX_TMPS_LEN];
		char c; char e;
		int t ;
		char u[11];
		for (int i = 0; i < 11; i++)
			u[i] = '\0';
		double d;
		int i;

		file.getline(s, MAX_TMPS_LEN, ',');
		sku(s);
	
		file.getline(n, MAX_TMPS_LEN, ',');
		name(n);
		
		
		file >> d >> c;
		price(d);
		
		file >> t >> e;
		
		taxed(t);
		file >> i >> c;
		quantity(i);
		file.getline(u, 9, ',');
		unit(u);
		

		
		file >> i;
		qtyNeeded(i);
		file.ignore();

		return file;
	}
//write function defintion to display output on screen
	ostream& AmaProduct::write(std::ostream& ostr, bool linear) const {
		if (err_.isClear() == false) {
			ostr << err_.message();
			
		}
		else {
			if (linear==true) {
ostr.setf(ios::fixed);
                ostr.setf(ios::left);

                ostr.width(MAX_SKU_LEN);
                ostr <<setfill(' ')<<sku() << "|";
                ostr.width(20);
                ostr.setf(ios::left);
                    ostr<< name() << "|";
                    ostr.unsetf(ios::left);
ostr.setf(ios::fixed);
                    ostr.precision(2);
                    ostr.width(7);
                    ostr << cost() << "|";
                    ostr.precision(6);
                    ostr.width(4);
                    ostr << quantity() << "|";
                    ostr.width(10);
                    ostr.setf(ios::left);
                    ostr << unit_ << "|"; 
                    ostr.unsetf(ios::left);
                    ostr.width(4);
                    
                    ostr<< qtyNeeded() << "|";
                 ostr.unsetf(ios::fixed); 
			}

			else {

				   ostr<<"Sku: " << sku() << endl;
                                   ostr.setf(ios::fixed);
                                   ostr.precision(2);
                 
			           ostr<<	"Name: " << name() << endl <<
					"Price: " << price() << endl <<
					"Price after tax: ";

					if (taxed()) {
						ostr << cost() << endl;
					}
					else if(!taxed())
						ostr << "N/A"<<endl;
					ostr<<"Quantity On Hand: " << quantity()<<" ";
					for (int i = 0; i < 11; i++)
					{
						if (unit_[i] != '\0')
							ostr << unit_[i];
					}
				
					ostr<<	"\nQuantity Needed: " << qtyNeeded();
				
			}
		}

		return ostr;
	}
//read function defintion to get user input
	istream& AmaProduct::read(istream& is) {
		err_.clear();
		cin.clear();
		cin.ignore();
		char s[MAX_SKU_LEN];
char n[256];
		double d;
		int i;
		int f = 0;
		char u[11];
		for (int i = 0; i < 11; i++)
			u[i] = '\0';
		char t;
		if (is.fail() == false) {
			err_.clear();
			

			cout << "Sku: ";
			is >> s;
			sku(s);
			cin.clear();
			cin.ignore();
			cout << "Name: ";
	is.getline(n,256);
			
			name(n);

			cin.clear();
			
			
			cout << "Unit: ";
			
			
			is >> noskipws >> u;
		
			unit(u);
			cin.clear();
		cin.ignore();
		
		
			cout <<"Taxed? (y/n): ";
			
			is >> t; 
			
				if (t == 'Y' || t == 'y' || t == 'N' || t == 'n')
				{
					if (t == 'Y' || t == 'y')
						taxed(true);
					else
						taxed(false);
				}
				else {
					
					
					
					err_.message("Only (Y)es or (N)o are acceptable\n");

					cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

					is.setstate(ios::failbit);
					f = 1;
				}
				
			
				if (f != 1) {
					cin.clear();
					cin.ignore();
					cout << "Price: ";
					is >> d;
					if (cin.fail()) {
						err_.message("Invalid Price Entry");
						is.setstate(ios::failbit);
					}
					else {
						price(d);
					}
				}
			if (err_.isClear()) {
				cin.clear();
				cin.ignore();
				cout << "Quantity On hand: ";
				is >> i;
				if (cin.fail()) {
					err_.message("Invalid Quantity Entry");
					is.setstate(ios::failbit);
				}
				else {
					quantity(i);
				}
			}

			if (err_.isClear()) {
				cin.clear();
				cin.ignore();
				cout << "Quantity Needed: ";
				is >> i;
				if (cin.fail()) {
					err_.message("Invalid Quantity Needed Entry");
					is.setstate(ios::failbit);
				}
				else {
					qtyNeeded(i);
					
				}
			}
		}

		return is;
	}

}

