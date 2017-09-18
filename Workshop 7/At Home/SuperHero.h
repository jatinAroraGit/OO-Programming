/***********************************************************
Workshop 7: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 07/16/17
FILE -Super Hero.h

// PURPOSE - this file includes declaration of a derived class and its member functions of the class and two constructors along with 2 non-member functions
*******************************************************************/


#ifndef SICT_SUPERHERO_H
#define SICT_SUPERHERO_H

#include "Hero.h"
using namespace sict;
namespace sict{
//derived class declaratiom
class SuperHero: public Hero {
//data members  
  int m_superPowerAttackBonus; // superpower:  attack bonus
    int m_superPowerDefendBonus;      // superpower:  defense
//memeber functions
public:
    // constructors  
    SuperHero();
    SuperHero(const char* name, 
            int maximumHealth, 
            int attack,
            
            int superPowerAttack, 
            int superPowerDefend);

    int getAttack() const; 
    int getDefend() const; 
 };
//non memeber functions
void applyDamage (SuperHero& A,  SuperHero& B);
const SuperHero & operator*(const SuperHero &, const SuperHero &);
}
#endif
