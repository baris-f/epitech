#ifndef _AWEAPON_HH_
# define _AWEAPON_HH_

#include <iostream>

class AWeapon
{
public:
  AWeapon(std::string const & name, int apcost, int damage);
  virtual ~AWeapon();
private:
  std::string	_name;
  int		_damage;
  int		_cost;
public:
  std::string const	getName() const;
  int			getAPCost() const;
  int			getDamage() const;
  virtual void		attack() const = 0;
};

#endif /* _AWEAPON_HH_ */
