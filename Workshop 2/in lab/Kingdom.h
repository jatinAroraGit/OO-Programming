/***********************************************************
 Workshop 2: LAB
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@

// PURPOSE - this is a header file for Kingdom.cpp. It contains struct Kingdom definition and declaration of display function
**************************************************************/
//guards to prevent multiple inclusions
#ifndef SICT_KINGDOM_H
#define SICT_KINGDOM_H      
namespace SICT{                    //namespace
#include <iostream>
	using namespace std;
	//structure defined
	struct Kingdom {
		char m_name[32];                    
		int m_population;
	};
	//function declaration
	void display(const Kingdom &obj);          

}

#endif                //guards closed


