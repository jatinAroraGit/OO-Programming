/***********************************************************
Workshop 4: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 6/13/17
FILE - Passenger.h


// PURPOSE - tis file includes declaration of class and its member functions.
*******************************************************************/

//header guards
#ifndef sict_Passenger_H
#define sict_Passenger_H
//sict namespace block

namespace sict {
#define LENGTH 32
	//declaration of class Passenger
	class Passenger {
		char pname[LENGTH];
		char pdestination[LENGTH];
		int year, month, day;
	public:
		//default Constructor
		Passenger();
		Passenger(const char * nm, const char * dstn);
		//constructor to modify values
		Passenger(const char* nm, const char* dstn, const int y, const int m, const int d);
		const char* name() const;
		bool canTravelWith(const Passenger & P) const;
		//decaration of isEmpty();
		bool isEmpty() const;
		//declaration of display()
		void display()const;
	}; //class close

}  //namespace close
#endif        //guards close

