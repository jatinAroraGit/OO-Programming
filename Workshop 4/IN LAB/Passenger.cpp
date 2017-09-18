/***********************************************************
Workshop 4: LAB
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/8/17
FILE - Passenger.cpp


// PURPOSE - tis file includes definitons of member functions of the class and two constructors.
*******************************************************************/

//headers
#include <iostream>
#include <cstring>
#include "Passenger.h"
// TODO: add the namespaces that you will be using here
using namespace std;
//namespace block
namespace sict {
   // default constructor
   Passenger::Passenger() {
	   name[0] = '\0';
	   destination[0] = '\0';
   }
   //constructor with 2 parameters
   Passenger::Passenger(const char* nm, const char* dstn) {
      if ((nm != nullptr && dstn != nullptr)) {
         strncpy(name, nm,32);
name[31]='\0';

         strncpy(destination, dstn,32); 
destination[31]='\0';
      
}
      else {
		  name[0] = '\0';
		  destination[0] = '\0';
      }
   }
   
   // defining isEmpty() function
    bool Passenger::isEmpty() const {
		if (name[0] == 0 || destination[0] == 0)
			return true;
		else
			return false;
   }
  
   //defining display() function
   void Passenger::display() const{
	   cout << "" << this->name << " - " << this->destination << endl;
        }
   
}
