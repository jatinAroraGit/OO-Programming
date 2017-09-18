/***********************************************************
Workshop 3: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________ |
!#^*(&!^@
DATE - 6/6/17
FILE - CRA_Account.cpp


// PURPOSE - tis file includes definitons of member functions of the class
*******************************************************************/

#include <iostream>
#include<cstring>
using namespace std;
#include "CRA_Account.h"

namespace sict {
	int s=0;
	//definiton of set function
	void CRA_Account::set(int year, double balance)
	{
		
				
		if (isValid())
		{
			if (s <MAX_YRS) {
				m_year[s] = year;
				m_balance[s] = balance;
			
				s++;
			
			}
			else
				cout << "Space Full" << endl;
		}
	}
	void CRA_Account::set(const char * familyName, const char * givenName, int sin)
	{
		
		sin_number = sin;
		bool result = isValid();
		
		if (result)
		{
		
			strncpy(famnm, familyName,MAX_NAME_LENGTH+1);
			strncpy(accnm, givenName,MAX_NAME_LENGTH+1);
			sin_number = sin;
			

		}
		else
			
		{
			
			strcpy(famnm, "\0");
			strcpy(accnm, "\0");
                        famnm[MAX_NAME_LENGTH]='\0';
			 accnm[MAX_NAME_LENGTH]='\0';

			
		}
	}







	//definiton of isValid function
	bool CRA_Account::isValid() const
	{
		int d=sin_number;
		
		int original[9] = { 0 };
		
		
		
		int m = sin_number;
		int j = 8;
		int c = 0;
		int k = 0;
		
		
		int sum = 0;
		int x = 0;
		int altsum = 0;
		int altsum2 = 0;

                int total, v, Newtotal;

		while (k == 0)
		{
			
			m = d % 10;
			d = d / 10;


			if (d != 0)
			{
				c++;
				original[j] = m;
				j--;

			}
			else {
				k = 1;
				c++;
			}original[0] = m;
			
			

		}


			

			if (c == 9)
			{
				for (int i = 1; i < c; i = i + 2)
				{
					sum = sum + original[i] + original[i];
			
					int t = -2;
					while (t != -1) {
						x = sum % 10;
						altsum = altsum + x;
						
						sum = sum / 10;
						if (sum == 0)
							t = -1;
					}
					sum = 0;
				}

				for (int h = 0; h < 8; h = h + 2)
				{
					altsum2 = altsum2 + original[h];
				}


			
				total = altsum + altsum2;
				int rem = total % 10;
				if (rem != 0)
				{
					v = 10 - rem;
					Newtotal = total + v;
					
				}
				else
					Newtotal = total;
				int diff = Newtotal - total;
				if (diff == original[8]) {
					
					return true;
					
				}
				else {
					
					return false;
			
				}
			}
                              return false;
		}
	

	//definiton of display function

	void CRA_Account::display() const
	{
		
	
		if (sin_number != 0)
		{
			int b = 0;

			cout << "Family Name: " << famnm << endl;
			cout << "Given Name : " << accnm << endl;
			cout << "CRA Account: " << sin_number << endl;
			while (b < MAX_YRS) {
				if (m_balance[b] > 2) {
					cout << "Year (" << m_year[b] << ") balance owing: " << m_balance[b] << endl;
					b++;
				}
				else
					if (-(m_balance[b]) > 2)
					{
						cout.setf(ios::fixed);
						
						cout.precision(2);
						cout << "Year (" << m_year[b] << ") refund due: " << -(m_balance[b]) << endl;
						b++;
					}
					else
					{
						cout.setf(ios::fixed);
						
						cout.precision(2);
						cout << "Year (" << m_year[b] << ") No balance owing or refund due!" << endl;
						b++;
					}
			}

		}
		else
			cout << "Account object is empty!" << endl;
		}

	}


