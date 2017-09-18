/***********************************************************
Workshop 9: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 7/27/17
FILE - String.cpp


// PURPOSE - tis file includes declaration of class and its member functions.
*******************************************************************/
//headers
#include <cstring>
#include <iostream>
#include "String.h"

using namespace std;

namespace sict {
	//default constructor
	String::String() {
		for (int i = 0; i < STRING_BUFFERSIZE; i++)
			m_pString[i] = '\0';
		
	}
	// constructor from C-string
	String::String(const char* pSource) {
		strncpy(m_pString, pSource, 51);
		
	}

	// copy constructor
	String::String(const String& other)
	{
		strcpy(this->m_pString, other.m_pString);

	}


	// assignment operator
	String& String::operator=(const String& other)
	{
		if (m_pString[0] != '\0')
		{
			for (int i = 0; i < STRING_BUFFERSIZE; i++)
			{
				m_pString[i] = '\0';
			}
			strcpy(m_pString, other.m_pString);
		}

		else
		{
			strcpy(m_pString, other.m_pString);
		}
		return *this;
	}

	// destructor
	String::~String()
	{
		for (int i = 0; i < STRING_BUFFERSIZE; i++)
		{
			m_pString[i] = '\0';
		}
	}

	//length funtion returns length of string
	int String::length() const
	{
		return strlen(m_pString);
	}

	// returns a pointer to the internal string
	String::operator const char *() const
	{
		return this->m_pString;
	}

	// returns true if the string is ""
	bool String::empty() const
	{
		return this->m_pString == nullptr || this->m_pString[0] == '\0';
	}

	// operator wrapper for empty()
	String::operator bool() const
	{
		return !empty();
	}

	// true if string *this and s2 are equal
	bool String::operator==(const String& s2) const
	{
		return (strcmp(this->m_pString, s2.m_pString) == 0);
	}


	// concatenate a char to the end of the string
	String& String::operator+=(const String& s2)
	{
		strcat(this->m_pString, s2.m_pString);
		return *this;
	}

	// adds two strings and returns it
	String String::operator+(const String& s2) const
	{
		String s1(this->m_pString);
		strcat(s1.m_pString, s2.m_pString);
		return s1;


	}
	// concatenate a char to the end of the string
	String& String::operator+= (char c)
	{
		int s = strlen(m_pString);
		if (s == 0)
		{
			m_pString[0] = c;
		}
		else
		{
			m_pString[s] = c;
		}

		return *this;
	}

	// output extract operator
	std::ostream& operator<<(std::ostream& ostream, const String &s)
	{
		ostream << s.operator const char *();
		return ostream;
	}
	// input insert operator
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
