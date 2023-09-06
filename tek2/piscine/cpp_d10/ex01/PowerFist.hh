#ifndef _POWERFIST_HH_
# define _POWERFIST_HH_

#include "AWeapon.hh"

class PowerFist : public AWeapon {
public :
  PowerFist();
  virtual ~PowerFist();

  virtual void	attack() const;
};

#endif /* _POWERFIST_HH_ */
