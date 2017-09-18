
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
//Final Project Milestone 6
//
// NAME - JATIN ARORA (136897162)
// DATE - 08/06/2017
// FILE - AidApp.cpp

// Purpose - This file containts defintion of  member functions and non member functions of AidApp class 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//headers
#include <cstring>
#include <new>
#include <iomanip>
#include "AidApp.h"
#include<limits>
using namespace std;
//namespCE

namespace sict{
//DEFAULT constructor
sict::AidApp::AidApp(const char * filename)
{
strcpy(filename_,"");
strcpy(filename_,filename);
for(int i=0;i<MAX_NO_RECS;i++)
product_[i]=nullptr;

noOfProducts_=0;
loadRecs();

}
//pause function definition
void sict::AidApp::pause() const
{
	cout << "\nPress Enter to continue...\n";
	cin.ignore();
	
}
//menu function definition
int sict::AidApp::menu()
{
unsigned int n;
		

cout <<
"Disaster Aid Supply Management Program" << endl <<
"1- List products" << endl <<
"2- Display product" << endl <<
"3- Add non-perishable product" << endl <<
"4- Add perishable product" << endl <<
"5- Add to quantity of purchased products" << endl <<
"0- Exit program" << endl <<
"> ";

cin >> n;

return n;
cin.ignore();
}
//loadrecs definition
void sict::AidApp::loadRecs()
{

int readIndex = 0;
	char c;
	Product* i;

	datafile_.open(filename_, ios::in);
	if (datafile_.fail()) {
		datafile_.clear();
		datafile_.close();
		datafile_.open(filename_, ios::out);
	}
	else {
		while (true) {
			datafile_ >> c;
			if (datafile_.fail()) {
				break;
			}
			datafile_.ignore();

			i = (Product*)readIndex;
			if (c == 'N') {
				i = new AmaProduct();
			}
			else if (c == 'P') {
				i = new AmaPerishable();

			}

			if (i != ((Product*)readIndex)) {
				i->load(datafile_);
				product_[readIndex++] = i;
			}
		}
	}

	noOfProducts_ = readIndex;
	datafile_.clear();
	datafile_.close();

}
//saverecs definition
void sict::AidApp::saveRecs()
{
	int c = 0;
	datafile_.open(filename_, ios::out);
	do {
		product_[c]->store(datafile_);
	} while (++c < noOfProducts_);

	datafile_.clear();
	datafile_.close();
}
}
//listProducts function
void sict::AidApp::listProducts() const
{
	int c = 0;
	double total = 0;

	
	cout <<"\n"<<
		" Row | SKU    | Product Name       | Cost  | QTY| Unit     |Need| Expiry   " << endl <<
		"-----|--------|--------------------|-------|----|----------|----|----------" << endl;

	do {
		cout << setfill(' ') << right << setw(4) << (c + 1) << " | " <<left<< *product_[c]<<endl;
		total += *product_[c];
		if(c==10){
		pause();
		}
	} while (++c < noOfProducts_);

	cout <<
		"---------------------------------------------------------------------------" << endl <<
		"Total cost of support: $" << fixed << setprecision(2) << showpoint << total << endl;
}
//search products function definition
int sict::AidApp::SearchProducts(const char * sku) const
{
int c = 0;
	int f=0;
	while (f==0 && c<noOfProducts_) {
	
		if (*product_[c] == sku){
		f=-1;
		c--;
		}
		
		c++;


	}
	if(f!=-1)
	c=-1;

	
	
	return c;
	
	
}
//addqty function definition
void sict::AidApp::addQty(const char * sku)
{
	cin.clear();
	cin.ignore();
	int c = SearchProducts(sku);
	int q, r = 0;
	Product* i;

	if (c == -1) {
		cout << "Not found!" << endl;
	}
	else {
		i = product_[c];
		i->write(cout, false);
		cout << endl << "\nPlease enter the number of purchased items: ";
		cin >> q;
		if (cin.fail()) {
			cout << "Invalid Quantity value!" << endl;
		}
		else {
			cin.ignore();
			r = i->qtyNeeded() - i->quantity();
			if (q <= r) {
				(*i) += q;
			}
			else {
				(*i) += r;
				cout << "Too much products, only " << r << " is needed, please return the extra " << (q + r) << " items." << endl;
			}
			saveRecs();
			cout << "\nUpdated!\n" << endl;
		}
	}
}
//addProduct function definition
void sict::AidApp::addProduct(bool isPerishable)
{
	Product* i;
	if (isPerishable) i = new AmaPerishable();
	else              i = new AmaProduct();

	cin >> *i;
	if (cin.fail()) {
		i->write(cout, false);
	}
	else {
		datafile_.open(filename_, ios::out | ios::app);
		i->store(datafile_);
		datafile_.close();
		cout << "\nProduct added\n" << endl;
	}
}
//run function definition
int sict::AidApp::run()
{
int f=0;
	char s[MAX_SKU_LEN];
	while(f==0){
		int n = menu();
	switch (n) {
		case 0:
		{
			f=-1;
			break;
		}
		case 1:
		{
			listProducts();
			pause();
			cin.ignore();
			break;
		}
		case 2:
		{
			cout << "\nPlease enter the SKU: ";
			cin >> s;

			int r = SearchProducts(s);
cout<<"\n";
			if (r != -1) {
				Product* i;
				i = product_[r];
				i->write(cout, false);
			}
			else
				cout << "NOT FOUND" << endl;
			cout << "\n";
			pause();
			cin.ignore();
			break;
		}
		case 3:
		{
			cout << "\n";
			addProduct(false);
			loadRecs();
			cin.ignore();
			break;
		}
		case 4:
		{
			cout << "\n";
			addProduct(true);
			loadRecs();
			cin.ignore();
			break;
		}
		case 5:
		{
			cin.ignore();
			cout << "\nPlease enter the SKU: ";
			cin >> s;
cout<<"\n";
			addQty(s);
			break;
		}
		default:{
		cout << " == Invalid Selection, try again. == ="<<endl ;
		break;
		}
		}
cin.clear();
}
	

	cout << "\nGoodbye!!" << endl;
	return 0;
}
	

