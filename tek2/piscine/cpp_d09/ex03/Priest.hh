#ifndef _PRIEST_HH_
# define _PRIEST_HH_

#include "Mage.hh"

class Priest: public Mage {
public :
  Priest(std::string, int);
  ~Priest();
public :
  int                   CloseAttack();
  void			Heal();
};

#endif /* _PRIEST_HH_ */
