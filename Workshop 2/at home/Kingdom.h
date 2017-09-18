#pragma once
/***********************************************************
Workshop 2: HOME
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@

// PURPOSE - this file contains definitons of overloaded "display" functions which differ in arguments they take.
**************************************************************/
//guards to prevent multiple inclusions
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H      
namespace SICT {                    //namespace
#include <iostream>
	using namespace std;
	//structure defined
	struct Kingdom {
		char m_name[32];
		int m_population;
	};
	//function declaration
	void display(const Kingdom &obj);
	void display(Kingdom* pKingdom, int count);

}

#endif                //guards closed
