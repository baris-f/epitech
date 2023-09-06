#ifndef _WARRIOR_HH_
# define _WARRIOR_HH_

#include "Character.hh"

class Warrior: public Character {
public :
  Warrior(std::string, int);
  ~Warrior();
private :
  std::string	_weaponName;
public :
  int                   CloseAttack();
  int                   RangeAttack();
};

#endif /* _WARRIOR_HH_ */
