/***********************************************************
Workshop 6: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/22/17
FILE - Contact.h

// PURPOSE - tis file includes declaration of member functions of the class and two constructors and one destrucutor.
*******************************************************************/
#ifndef sict_Contact_H_
#define sict_Contact_H__
//namespace block
namespace sict {
#define L 21
	//class declaration
	class Contact
	{
		char name[L];
		long long* phn;
		int Nphn;
		//public memebr functions
	public:
		// default constructor 
		Contact();
		// constructor with parameters 
		Contact(const char* name, const long long* Number, const int noPhNumber);
		// destructor 
		~Contact();
		// display function 
		void display() const;
		//isEmpty function 
		bool isEmpty() const;

	};//class close	
}//namespace close
#endif