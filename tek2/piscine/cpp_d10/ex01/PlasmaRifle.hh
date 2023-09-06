#ifndef _PLASMARIFLE_HH_
# define _PLASMARIFLE_HH_

#include "AWeapon.hh"

class PlasmaRifle : public AWeapon {
public :
  PlasmaRifle();
  virtual ~PlasmaRifle();

  virtual void	attack() const;
};

#endif /* _PLASMARIFLE_HH_ */
