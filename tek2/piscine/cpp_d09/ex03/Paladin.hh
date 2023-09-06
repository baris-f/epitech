#ifndef _PALADIN_HH_
# define _PALADIN_HH_

#include "Warrior.hh"
#include "Priest.hh"

class Paladin: public Warrior, public Priest {
public :
  Paladin(std::string, int);
  ~Paladin();
public :
  int                   CloseAttack();
  int                   RangeAttack();
  void                  Heal();
  int			Intercept();
  void			RestorePower();
};

#endif /* _PALADIN_HH_ */
