/***********************************************************
Workshop 9: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 7/27/17
FILE - String.h


// PURPOSE - tis file includes defintion of class and its member functions.
*******************************************************************/
//headers
#ifndef SICT_STRING_H_
#define SICT_STRING_H_

#include <iostream>
//defining a value
#define STRING_BUFFERSIZE 100
//namespae block
namespace sict
{
	//class declaration
	class String
	{
		//data member
		char m_pString[STRING_BUFFERSIZE];
		//public member functions
	public:
		// default constructor
		String();     
		// constructor from C-string
		String(const char* src);    
		// copy constructor
		String(const String& src); 
		// assignment operator
		String& operator=(const String& src); 
		// destructor
		~String();                     
		//functions
		int capacity() { return STRING_BUFFERSIZE; }

		// the length of the string
		int         length()                    const;
		// returns true if the string is ""
		bool        empty()                  const;

		// concatenate a char to the end of the string
		String&     operator+=  (char c);
		// concatenate two strings
		String&     operator+=  (const String& s2);
		// adds two strings and returns it
		String      operator+   (const String& s2) const;
		// returns a pointer to the internal string
		operator    const char* ()                  const;
		// operator wrapper for empty()
		operator bool()                  const;
		// true if string *this and s2 are equal
		bool        operator==(const String& s2)const;

	};
     //helper functions
	// output extract operator
	std::ostream&    operator<<  (std::ostream&, const String&);
	// input insert operator
	std::istream&    operator>>  (std::istream&, String&);

};

#endif
