//headers
#include <cstring>
#include <iostream>
#include "String.h"


using namespace std;
//namepace block;
namespace sict {


	//////////////////////////////////////////////////////
	//
	// Default Constructor
	// String::String(int capacity);
	//
	// initialize the string with an internal buffer capacity of
	// "capacity."
	// default capacity is 1 (minimum needed for an empty string)
	//
	//
	String::String(int capacity) {
		m_capacity = capacity;
		m_pString = new char[capacity];
	
		m_pString[0] = '\0';

	}

	//////////////////////////////////////////////////////
	//
	// String::String(const char* p, int capacity);
	//
	// Construct a String from a char array
	// Should initialize the internal buffer to at least
	// the length of the string need to hold pSource,
	// or capacity, whichever is greater.
	//
	//
	String::String(const char* pSource, int capacity) {

		int len = strlen(pSource) + 1;
		if(capacity < len){
			this->m_pString = new char[len];
			strcpy(m_pString, pSource);
			m_capacity = len;
		}
	else 
	{
		m_pString = new char[capacity];
		strcpy(m_pString, pSource);
		m_capacity = capacity;
	}
	}

	//////////////////////////////////////////////////////
	//
	// String::String(const String &s, int capacity);
	//
	// Copy constructors
	//
	// Construct a String from another String
	//
	//
	String::String(const String& other, int capacity)
	{

		int len = strlen(other.m_pString) + 1;
		if (capacity >= len) {
			m_capacity = capacity;
			m_pString = new char[capacity];
			strcpy(m_pString, other.m_pString);
			
		}
		else {
			m_capacity = len;
			this->m_pString = new char[len];
			strcpy(m_pString, other.m_pString);
			
		}

	}



	//////////////////////////////////////////////////////
	//
	// String::resize(int newsize)
	//
	// resize the internal buffer to the value given
	// do NOT shrink the string buffer smaller than
	// that needed to hold the existing string!
	// (length + 1);
	//
	void String::resize(int newsize)
	{
		char* new_;
		if (newsize > capacity()) {
			m_capacity = newsize;
			new_ = new char[m_capacity];
			strcpy(new_, m_pString);

			delete[] m_pString;
		
			m_pString =new_;
		}
	}


	//////////////////////////////////////////////////////
	//
	// String::operator=(const String& other)
	//
	// Assignment operator
	// copy string "other" to this object
	//
	//
	String& String::operator=(const String& other)
	{
		if (this != &other) {
			m_capacity = other.m_capacity;
			
				delete[] m_pString;
			
			if (other.m_pString != nullptr) {
				this->m_pString = new char[m_capacity];
				strcpy(m_pString, other.m_pString);
			}
			else {
				m_pString = nullptr;
			}
		}
		return *this;
	}


	//////////////////////////////////////////////////////
	//
	// String::~String
	//
	// destructor
	//
	// clean up the internal string buffer
	//
	String::~String()
	{
		
		delete[] m_pString;
		m_pString[0]='\0';
	}

	//////////////////////////////////////////////////////
	//
	// String::length()
	//
	// return the length of the string
	//
	//
	int String::length() const
	{
		return strlen(m_pString);
	}


	//////////////////////////////////////////////////////
	//
	// String::operator const char*() const
	//
	// convert the String to a char*
	//
	//
	String::operator const char *() const
	{
		return (const char*)m_pString;
	}


	//////////////////////////////////////////////////////
	//
	// String::empty()
	//
	//
	// returns true if the string is empty
	// i.e. either the first char is \0, or
	// length is 0.
	bool String::empty() const
	{
		return (m_pString[0] == '\0' || length() == 0);
	}

	//////////////////////////////////////////////////////
	//
	// String::operator bool()
	//
	// same as empty(), just wrapped in an operator
	//
	//
	String::operator bool() const
	{
		return !empty();
	}


	//////////////////////////////////////////////////////
	//
	// String::operator==(const String& s2) const
	//
	// returns true if *this == s2.
	// You can use the strcmp function to check if
	// two strings are equal, or write your own
	// treating the string as a char-array
	//
	bool String::operator==(const String& s2) const
	{
		return strcmp(this->m_pString, s2.m_pString) == 0;
	}


	//////////////////////////////////////////////////////
	//
	// String::operator+=(const String& s2)
	//
	// Concatenates s2 to the end of *this
	//
	// implements *this = (*this + s2)
	// return *this
	//
	//
	String& String::operator+=(const String& s2)
	{
		int len = strlen(m_pString) + strlen(s2.m_pString) + 1;
		if (m_capacity < len) {
			this->resize(len);
		}
		strcat(m_pString, s2.m_pString);
		return *this;
	}



	//////////////////////////////////////////////////////
	//
	// String::operator+(const String& s2) const
	//
	// implements the operator (*this + s2)
	// returns the expression
	// DOES NOT MODIFY *this
	//
	//
	String String::operator+(const String& s2) const
	{
		String str;
		str = m_pString;
		str += s2;

		return str;
	}

	//////////////////////////////////////////////////////
	//
	// String::operator+=(char c)
	//
	// Adds a single char c to the end of the string in *this
	// Grows the string buffer if necessary.
	//
	String& String::operator+= (char c)
	{
		int len = length();
		resize(capacity() + 1);
		m_pString[len] = c;
		m_pString[len + 1] = '\0';

		return *this;
	}



	//////////////////////////////////////////////////////
	//
	// String::substr
	//
	// Returns a substring of the current string. In case of error
	// return an empty String() object instead.
	//
	// return the string slice starting at index, at most len characters
	//
	// both index and len have to lie inside the string. If they do not, then
	// that is an error
	//
	String String::substr(int index, int len) const
	{
		String string;
		
		int l = len - index;
		if (len > 0 && index <= len && index >= 0) {
			string.resize(l + 1);
			for (int i = index; i < index + len && m_pString[i] != '\0'; i++) {
				string += m_pString[i];
			}
		}
		return string;
	}

	//////////////////////////////////////////////////////
	//
	// operator<<
	//
	// Print the string to the output stream
	//
	// clean up the internal string buffer
	//
	std::ostream& operator<<(std::ostream& ostream, const String &s)
	{
		ostream << (const char*)s;
		return ostream;
	}

	//////////////////////////////////////////////////////
	//
	// operator>>
	//
	// Input a string from an input stream into the String s
	//
	// Note: the input can be ANY length in character. You will need to
	// read it one char at a time.
	//
	std::istream& operator>>(std::istream& istream, String &s)
	{
		s = "";
		char tempC = 0;
		do
		{
			tempC = istream.get();
			if (tempC != '\n')
			{
				s += tempC;
			}
			else
				break;
		} while (1);
		return istream;
	}


}