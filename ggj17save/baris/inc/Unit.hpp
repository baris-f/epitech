#ifndef UNI
#define UNI

#include "Entity.hpp"

#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))

class	Unit : public Entity
{
public:
  Unit(sf::Texture*, const std::string);
  virtual ~Unit(){};
protected:
  int		_dmg;
  float		_range;
  int		_fireRate;

  int		_fireTime;
  int		_targetTime;

  bool		_attacked;

  Entity*	_target;
public:
  void		updateTarget();
  bool		targetInRange();
  void		attack();

  int		getDmg() const{ return (_dmg);};
  void		setDmg(int dmg){_dmg = dmg;};
  float		getRange() const{ return (_range);};
  void		setRange(float range){_range = range;};
  int		getFireRate() const{ return (_fireRate);};
  void		setFireRate(int fireRate){_fireRate = fireRate;};
};
#endif
