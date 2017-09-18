/***********************************************************
Workshop 7: HOME
_____________________
| NAME - JATIN ARORA  |
| 136897162           |
|_____________________|
!#^*(&!^@
DATE - 07/16/17
FILE - Hero.h

// PURPOSE - this file includes declaration of member functions of the class and two constructors along with 2 non-member functions
*******************************************************************/

//guards
#ifndef SICT_HERO_H
#define SICT_HERO_H
#include <iostream>
#define L 41
//namespace block
namespace sict{
//class declaration
class Hero {
//private data members
	char m_name[L];
	int  m_attack;
	int  m_maximumHealth;
	int  m_health;

	bool isEmpty() const;
//public member functions
public:
	// constructors
	Hero();
	Hero(const char name[], int maximumHealth, int attack);

	// member functions
	void respawn();
	bool isAlive() const;
	int  getAttack() const { return m_attack; }
	void deductHealth(int);
	void display(std::ostream& obj) const;
	// friend helper function to insert name into ostream
	friend std::ostream& operator<<(std::ostream&, const Hero&);
};
//non-member functions
void applyDamage(Hero& A, Hero& B);
const Hero & operator*(const Hero &, const Hero &);
}
#endif
