/***********************************************************
Workshop 2: LAB
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@


// PURPOSE - this file contains function display definiton.
****************************************************************/


#include<iostream>
#include "Kingdom.h"        //header included
using namespace std;
namespace SICT {

	//function defined   // accepts object of Kingdom structure as arguments and then displays kingdom name and population
	void display(const Kingdom &obj)             
	{
		cout << obj.m_name << ", population " << obj.m_population << endl;

	}




}


