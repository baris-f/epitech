#ifndef ENT
#define ENT

#include "Object.hpp"
#include "IListener.hpp"


class	Entity : public Object, public IListener
{
public:
  Entity(sf::Texture*, const std::string, float, float);
  Entity(sf::Texture*, const std::string, const sf::Vector2f&);
  virtual ~Entity(){};
protected:
  int	_life;
  int	_lvl;
public:
  void	draw(sf::RenderWindow*);
  void	update(Data *);
  virtual void func();
};

#endif
