#ifndef UNI
#define UNI

#include "Entity.hpp"

class	Unit : public Entity
{
public:
  Unit(sf::Texture*, const std::string, float, float);
  Unit(sf::Texture*, const std::string, const sf::Vector2f&);
  ~Unit(){};
protected:
  int		_dmg;
  float		_range;
  int		_fireRate;

  int		_fireTime;
  int		_targetTime;

  Entity*	_target;
public:
   void		findTarget();
};

#endif
