/***********************************************************
Workshop 4: LAB
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/8/17
FILE - Passenger.h


// PURPOSE - tis file includes declaration of class and its member functions.
*******************************************************************/

//header guards
#ifndef sict_Passenger_H
#define sict_Passenger_H
//sict namespace block
namespace sict {
   //declaration of class Passenger
   class Passenger {  
      char name[32];
      char destination[32];
   public:
      //default Constructor
	   Passenger(); 
	   //constructor to modify values
      Passenger(const char* nm, const char* dstn);
     //decaration of isEmpty();
      bool isEmpty() const;
      //declaration of display()
      void display()const;
   }; //class close

}  //namespace close
#endif        //guards close
