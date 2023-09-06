#ifndef ENT
#define ENT

#include "Object.hpp"

class	Entity : public Object
{
public:
  Entity(sf::Texture*, const std::string);
  virtual ~Entity(){};
protected:
  int		_hp;
  int                   _lifemax;
  sf::RectangleShape    _shape;
  sf::RectangleShape    _shapeBack;
  int		_lvl;
public:
  int		getHp() const { return (_hp);	};
  void		setHp(int hp) { _hp = hp;	};
  int		getLvl() const { return (_lvl);	};
  void		setLvl(int lvl) { _lvl = lvl;	};
};

#endif
