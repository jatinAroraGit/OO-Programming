///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Final Project Milestone 3
//
// NAME - JATIN ARORA (136897162)
// DATE - 7/12/2017
// FILE - Streamable.h

// Purpose - This file contains definiton of several virtual member functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//guards
#ifndef SICT_DATE_H__
#define SICT_DATE_H__

//headers
#include<iostream>
#include<fstream>
using namespace std;
//namespace block
namespace sict {
//class declaration
	class Streamable {
//class declaration
	public:
//virtual member functions
  virtual fstream & store(fstream & file, bool addNewLine) const
        {
                return file;
        }
       virtual fstream & load(std::fstream & file)
        {
                return file;
        }
       virtual ostream & write(ostream & os, bool linear) const
        {
                return os;
        }
      virtual  istream & read(istream & is)
        {
                return is;
        }

	};
}
#endif
