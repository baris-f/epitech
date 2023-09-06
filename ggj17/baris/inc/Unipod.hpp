#ifndef POD
#define POD

#include "Unit.hpp"

class	Unipod : public Unit
{
public :
  Unipod(sf::Texture *text, std::string type);
  virtual ~Unipod(){};
protected:
  float	_speed;
public:
  void	move();

  float	getSpeed() const { return (_speed);};
  void	setSpeed(float speed){ _speed = speed;};
};

#endif
