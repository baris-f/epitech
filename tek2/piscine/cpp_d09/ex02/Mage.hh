#ifndef _MAGE_HH_
# define _MAGE_HH_

#include "Character.hh"

class Mage: public Character {
public :
  Mage(std::string, int);
  ~Mage();
public :
  int                   CloseAttack();
  int                   RangeAttack();
  void			RestorePower();
};

#endif /* _MAGE_HH_ */
