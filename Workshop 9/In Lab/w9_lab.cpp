/***********************************************************
Workshop 9: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 7/27/17
FILE - w9_lab.cpp


// PURPOSE - tis file includes the main function which test our code.
*******************************************************************/
#include <iostream>
#include <cassert>
#include "String.h"

using namespace std;
using namespace sict;


int
main()
{

	String s("Hello");
	String s2;

	cout << "Testing constructors" << endl;
	if (!s.empty() && s2.empty())
	{
		cout << "PASS, Constructors!" << endl;
	}
	else
	{
		cout << "FAIL, check constructors" << endl;
	}

	cout << "Testing bool operator" << endl;
	if (s && !s2)
	{
		cout << "PASS, operator bool()." << endl;
	}
	else
	{
		cout << "FAIL, operator bool()" << endl;
	}

	if (s.length() == 5 && s2.length() == 0)
	{
		cout << "PASS: string length works" << endl;
	}
	else
	{
		cout << "FAIL: string length reports " << s.
			length() << "for string hello" << endl;
	}

	s = "Hello";
	s = "Hello";
	s = "Hello";
	s = "Hello";
	s = "Hello";
	s += ' ';
	s2 = "World";
	s2 = "World";
	s2 = "World";
	s2 = "World";
	s2 = "World";


	cout << "testing operator+  :" << (s + s2) << endl;
	cout << "testing operator+= :" << (s += s2) << endl;

	if (s == String("Hello World"))
	{
		cout << "PASS Operators test" << endl;
	}
	else
	{
		cout << "FAIL operator+ and operator+= test" << endl;
	}

	String s3(s);
	if (s3 == s)
	{
		cout << "PASS Copy constructor test passes" << endl;
	}
	else
	{
		cout << "FAIL copy constructor test fails!" << endl;
	}

	// Complex tests
	// Make 2 strings: "0" and "1"
	// Join them together to for a string "01"
	// Join that with itself to make a new string "0101"
	// 
	// Keep doing it...confirm that the string grows properly.
	s = "0";
	assert(s.length() == 1);
	s2 = "1";
	s3 = (s + s2);
	s = s2 = s3;
	assert(s.length() == 2);
	s3 = (s + s2);
	s = s2 = s3;
	assert(s.length() == 4);
	s3 = (s + s2);
	s = s2 = s3;
	assert(s.length() == 8);
	s3 = (s + s2);
	s = s2 = s3;
	assert(s.length() == 16);
	s3 = (s + s2);
	s = s2 = s3;
	assert(s.length() == 32);
	s3 = (s + s2);
	s = s2 = s3;
	assert(s.length() == 64);

	cout << "PASS: string concatenation up to 64 bytes" << endl;



	String myInput;
	cout << "Type in the following line" << endl <<
		"the quick brown fox jumped over the lazy dog" << endl;
	cin >> myInput;
	if (myInput == String("the quick brown fox jumped over the lazy dog"))
	{
		cout << "PASS: iostream input" << endl;
	}
	else
	{
		cout << "FAIL: iostream input" << endl;
	}
	cout <<
		"testing output. Let the submit script confirm that the output matches your input."
		<< endl;
	cout << myInput << endl;



}
