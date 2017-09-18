/***********************************************************
Workshop 7: LAB
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 07/13/17
FILE - Hero.h

// PURPOSE - this file includes declaration of member functions of the class and two constructors along with 2 non-member functions
*******************************************************************/

//guards
#ifndef sict_HERO_H
#define sict_ HERO_H
#include <iostream>
#define L 41
//class declaration
namespace sict{
class Hero {
//private data members
    char m_name[L];    
    int  m_attack;
    int  m_maximumHealth;
    int  m_health;
    
   

public:
    // constructors
    Hero ();
    Hero (const char name[], int maximumHealth, int attack);

    // member functions
        bool isEmpty () const;
    
        void respawn();
	bool isAlive() const;
    int  getAttack () const         {    return m_attack;       }
    void deductHealth(int);
	void display(std::ostream& obj) const;
    // friend helper function to insert name into ostream
	friend std::ostream& operator<<(std::ostream&, const Hero&);
};
//non-member functions
void applyDamage (Hero& A, Hero& B);
const Hero & operator*(const Hero &, const Hero &);
}
#endif
