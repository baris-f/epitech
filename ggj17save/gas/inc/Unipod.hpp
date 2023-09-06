#ifndef POD
#define POD

#include "Unit.hpp"

class	Unipod : public Unit
{
protected:
  float	_speed;
public:
  void	move(sf::Vector2f);
};

#endif
