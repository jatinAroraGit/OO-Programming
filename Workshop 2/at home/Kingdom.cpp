/***********************************************************
Workshop 2: HOME
 _____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@


// PURPOSE - this file contains definiton of overloaded "display" functions.
****************************************************************/


#include<iostream>
using namespace std;
#include "Kingdom.h"
namespace SICT {

	//header included
	using namespace std;
	//function defined   // accepts object of Kingdom structure as arguments and then displays kingdom name and population
	void display(const Kingdom &obj)            
	{
		cout << obj.m_name << ", population " << obj.m_population << endl;

	}


	//overloded function which differs in set of arguments accepted
	void display(Kingdom* pKingdom, int count)        
	{
int sum=0;    int c=1;
		cout << "------------------------------" << endl;
		cout << "Kingdoms of SICT" << endl; 
                cout << "------------------------------" << endl;

		
		for (int j = 0; j < count; j++)
		{
			cout <<""<< c <<". " << pKingdom[j].m_name << ", population " << pKingdom[j].m_population << endl;
		sum=sum+pKingdom[j].m_population;
c++;

}
 cout << "------------------------------" << endl;

cout<<"Total population of SICT: "<<sum<<endl;
 cout << "------------------------------" << endl;

	}




}


