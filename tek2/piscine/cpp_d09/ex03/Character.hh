#ifndef _CHARACTER_HH_
# define _CHARACTER_HH_

#include <iostream>

class	Character {
public :
  enum AttackRange { CLOSE, RANGE};
public :
  Character(std::string const, int lvl);
  ~Character();
private :
  std::string	_name;
  std::string	_Race;
  int		_lvl;
  int		_Pv;
  int		_Power;
protected :
  int		_Strengh;
  int		_Stamina;
  int		_Intelligence;
  int		_Spirit;
  int		_Agility;
public :
  AttackRange	Range;

public :
  std::string const&	getName() const;
  int			getLvl() const;
  int			getPv() const;
  void			setPv(int);
  int			getPower() const;
  void			setPower(int Power);
  int			CloseAttack();
  int			RangeAttack();
  void			Heal();
  void			RestorePower();
  void			TakeDamage(int _damage);
};

#endif /* _CHARACTER_HH_ */
