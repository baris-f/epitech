#include "Unit.hpp"
#include "proto.h"

/*#define MAX(x,y) ((x)>(y)?(x):(y))
  #define MIN(x,y) ((x)<(y)?(x):(y))*/

/*float   dista(sf::Vector2f pos1, sf::Vector2f pos2)
{
  return (sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2)));
  }*/

Unit::Unit(sf::Texture* text, const std::string type)
  : Entity(text, type)
{
}

bool	Unit::targetInRange()
{
  if (!_target)
    return (false);
  if (_target->getType() == "ally" || _target->getType() == "building")
    {
      if (dist(sf::Vector2f(_target->getPos().x + _target->getRekt().width, _target->getPos().y), getPos()) < _range)
	return (true);
    }
  else
    if (dist(_target->getPos(), getPos()) < _range)
      return (true);
  return (false);
}

void	Unit::attack()
{
  if (!_target)
    return ;
  if (_fireTime > 0)
    {
      _fireTime--;
      return ;
    }
  _fireTime = _fireRate;
  _attacked = true;
  //drawShoot(this, _target);
  _target->setHp(_target->getHp() - _dmg);
}

void	Unit::updateTarget()
{
  _target = findTarget(this);
}
