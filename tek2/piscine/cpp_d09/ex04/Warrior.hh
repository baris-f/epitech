#ifndef _WARRIOR_HH_
# define _WARRIOR_HH_

#include "Character.hh"

class Warrior: virtual public Character {
public :
  Warrior(std::string, int);
  Warrior(const std::string&);
  ~Warrior();
protected :
  std::string	_weaponName;
public :
  int                   CloseAttack();
  int                   RangeAttack();
};

#endif /* _WARRIOR_HH_ */
