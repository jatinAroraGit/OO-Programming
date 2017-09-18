/***********************************************************
Workshop 7: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 07/13/17
FILE - Hero.cpp

// PURPOSE - this file includes defintion of member functions of the class and two constructors along with 2 non-member functions
*******************************************************************/

#define _CRT_SECURE_NO_WARNINGS
//headers
#include <cstring>
#include <iostream>
#include "Hero.h"
using namespace std;
namespace sict{
//////////////////////////////////////////////
// Default constructor
//
Hero::Hero () 
{
    m_name[0]='\0';
	m_attack=0;
	m_maximumHealth=0;
    m_health=0;
}

///////////////////////////////////////////////////
// Constructor to initialize values to values input by user
// 
Hero::Hero (const char name[], int maximumHealth, int attack) 
{
strncpy(m_name, name, L);
m_name[L - 1] = '\0';
m_maximumHealth = maximumHealth;
m_attack = attack;
m_health = m_maximumHealth;


}

// Hero::isEmpty ()
// return true if the Hero object is uninitialized

bool Hero::isEmpty () const 
{
	if (m_name[0] =='\0' && m_maximumHealth == 0)
		return true;
	else
		return false;
}


//respawn()function to  set the Hero object's health back to full

void Hero::respawn() 
{
	m_health = m_maximumHealth;

}
//isAlive function to check health of hero is greater than zero or not
bool Hero::isAlive() const
{
	
	return m_health > 0;
}


//deduceHealth function reduces the helath value by the attack value recieved
void Hero::deductHealth(int attack)
{
	m_health = m_health - attack;
	
}
//display function definiton
void Hero::display(std::ostream & obj) const
{
	if (m_name != nullptr)
	{
		cout << m_name << endl;
	}
}
///operator<< to return hero name
std::ostream & operator<<(std::ostream &out, const Hero &h)
{
	out<<h.m_name;
	return out;
}

//////////////////////////////////////////////////////////////////

//applyDamage()function defintion to calculate damage
void applyDamage (Hero& A, Hero& B) 
{
	bool rA = A.isAlive();
	bool rB = B.isAlive();
	if (rA == true && rB == true)
	{
		int atkB = B.getAttack();

		int atkA = A.getAttack();

		A.deductHealth(atkB);

		B.deductHealth(atkA);
	}

	
}


//operator* function defintion
const Hero & operator* (const Hero & first, const Hero & second) {
	// Display the names of the people fighting
	
	cout << "AncientBattle! " << first << " vs " << second << " : ";

	
	Hero A = first;
	Hero B = second;
//	int atci = A.getAttack();

	
	const Hero *winner = nullptr;

	// Now A will fight B, and winner will point to the winner.    
	// Main fight loop
	unsigned int rounds = 0;
	// loop while both are still alive
	// fight for 100 rounds
////	bool chk = A.isAlive();
	
	while (A.isAlive() && B.isAlive() && rounds < 100)
	{

		rounds++;
		
		applyDamage(A, B);
	}

	
	bool draw;

	if (A.isAlive() && B.isAlive()) { draw = true; }
	else { draw = false; }

	
	 
	if (draw)
	{
		winner = &first;
	}
	else if (A.isAlive())
	{
		winner = &first;
	}
	else
	{
		winner = &second;
	}

	// print out the winner
	cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;

	// return a reference to the winner
	return *winner;
}
}
