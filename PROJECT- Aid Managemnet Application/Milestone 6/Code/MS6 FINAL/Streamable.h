#ifndef SICT_STREAMABLE_H__
#define SICT_STREAMABLE_H__


#include<iostream>
#include<fstream>
using namespace std;

namespace sict {

	class Streamable {
	public:
		virtual	fstream& store(fstream& file, bool addNewLine = true)const {
			return file;
	}
	
		virtual	fstream& load(std::fstream& file) {
			return file;
	}
		virtual	ostream& write(ostream& os, bool linear)const {
			return os;
	}
		virtual	istream& read(istream& is) {
			return is;
	}
	};
}
#endif
