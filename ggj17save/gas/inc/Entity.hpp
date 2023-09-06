#ifndef ENT
#define ENT

#include "Object.hpp"

class	Entity : public Object
{
public:
  Entity(sf::Texture*, const std::string, float, float);
  Entity(sf::Texture*, const std::string, const sf::Vector2f&);
  ~Entity(){};
protected:
  int		_hp;
  int		_lvl;
  Lifebar	_lifebar;
public:
  void	draw(sf::RenderWindow*);
};

#endif
