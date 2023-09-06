#ifndef _HUNTER_HH_
# define _HUNTER_HH_

#include "Warrior.hh"

class Hunter: public Warrior{
public :
  Hunter(std::string, int);
  ~Hunter();
public :
  int                   CloseAttack();
  int                   RangeAttack();
  void                  Heal();
  int			Intercept();
  void			RestorePower();
};

#endif /* _HUNTER_HH_ */
