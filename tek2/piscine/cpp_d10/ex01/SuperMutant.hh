#ifndef _SUPERMUTANT_HH_
# define _SUPERMUTANT_HH_

#include "AEnemy.hh"

class SuperMutant : public AEnemy {
public :
  SuperMutant();
  virtual ~SuperMutant();

  virtual void	takeDamage(int);
};

#endif /* _SUPERMUTANT_HH_ */
