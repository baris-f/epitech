#ifndef _CHARACTER_HH_
# define _CHARACTER_HH_

#include <iostream>
#include "AEnemy.hh"
#include "AWeapon.hh"

class Character {
public :
  Character(std::string const & name);
  virtual ~Character();
protected :
  std::string	_name;
  int		_AP;
  AWeapon*	_weapon;
public :
  void	recoverAP();
  void	equip(AWeapon*);
  void	attack(AEnemy*);
  std::string const getName() const;
  AWeapon* getWeapon() const;
  int	getAP() const;
};

std::ostream &	operator<<(std::ostream & os, Character const &);
#endif /* _CHARACTER_HH_ */
