/***********************************************************
Workshop 6: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/27/17
FILE - Contact.h

// PURPOSE - this file includes declaration of member functions of the class and two constructors and one destrucutor and another copy constructor.
*******************************************************************/
#ifndef sict_Contact_H_
#define sict_Contact_H__
//namespace block

namespace sict {
#define L 20
	//class declaration
	class Contact
	{
		char name[L];
		long long* phn;
		int Nphn;
	//member functions
	public:
		//default constructor
		Contact();
		//constructor with 3 parameters
		Contact(const char* name, const long long* Number, const int noPhNumber);
		//copy constructor
		Contact(const Contact& other);
		//destructor
		~Contact();
		//display function declaration
		void display() const;
		//isEmpty declaration
		bool isEmpty() const;
		//copy assignment operator 
		Contact& operator=(const Contact& other);
		//overloaded += operator function
		Contact & operator+=(long long phoneNumber);
		
	}; //class close
}//namespace close
#endif
