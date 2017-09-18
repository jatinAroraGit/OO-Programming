
/***********************************************************
Workshop 7: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 07/16/17
FILE - SuperHero.cpp

// PURPOSE - this file includes definition of member functions of the class and two constructors along with 2 non-member functions
*******************************************************************/

#include <iostream>
#include "SuperHero.h"
using namespace std;
namespace sict{
/////////////////////////////////////////////
// Default constructor
//
SuperHero::SuperHero() : Hero()
{
	 m_superPowerAttackBonus = 0;
	 m_superPowerDefendBonus = 0;
}  
        
//////////////////////////////////////////////
// Constructor with 5 arguments
//
SuperHero::SuperHero( const char* name, int maximumHealth, int attack,
                int superPowerAttack, int superPowerDefend
        )  : Hero(name, maximumHealth, attack)
{ 
	m_superPowerAttackBonus = superPowerAttack;
	m_superPowerDefendBonus = superPowerDefend;
}


//getAttack() function to return attack value of hero
int SuperHero::getAttack() const 
{ 
	int a = Hero::getAttack();
	int ATK = a + m_superPowerAttackBonus;
	return ATK;
}


//getDefend() shows superheroes defense value
//
int SuperHero::getDefend() const 
{ 
	return m_superPowerDefendBonus;
}



//applyDamage() claculaes and dictates battle between heroes
void applyDamage (SuperHero& A, SuperHero& B) {

    int damage_A = B.getAttack() - A.getDefend();
    int damage_B = A.getAttack() - B.getDefend();

    if (damage_A < 1) 
    {
        damage_A = 1;
    }
    if (damage_B < 1)
    {
        damage_B = 1;
    }

    A.deductHealth(damage_A);
    B.deductHealth(damage_B);
}
//operator* ()funciton controls battles between heroes and shows outputs
const SuperHero & operator* (const SuperHero & first, const SuperHero & second) {

	// Display the names of the people fighting

	cout << "SuperFight! " << first << " vs " << second << " : ";

	// make a copy of the objects

	SuperHero A = first;
	SuperHero B = second;
	const SuperHero *winner = nullptr;

	unsigned int rounds = 0;
	// loop while both are still alive
	while (A.isAlive() && B.isAlive() && rounds< 100)
	{
		rounds++;
		applyDamage(A, B);
	}

	// if we got here, then one Hero is dead, or it was a draw.
	bool draw = A.isAlive() && B.isAlive();

	// if it was a draw, then we decide by tossing an unfair coin and always
	// declare that A was the winner. 
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

	cout << "Winner is " << *winner << " in " << rounds << " rounds." << endl;

	return *winner;
}
}
