#ifndef _AENEMY_HH_
# define _AENEMY_HH_

#include <iostream>

class AEnemy
{
public:
  AEnemy(int hp, std::string const & name);
  virtual ~AEnemy();
protected:
  std::string	_type;
  int		_hp;
public:
  std::string const	getType() const;
  int			getHP() const;
  virtual void		takeDamage(int);
};

#endif /* _AENEMY_HH_ */
