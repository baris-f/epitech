#ifndef PHASER_H_
# define PHASER_H_

#include <iostream>
#include "Sounds.h"

class Ammo;

class Phaser
{
 public:
  enum AmmoType
  { REGULAR, PLASMA, ROCKET };
 public:
  Phaser(int maxAmmo = 20, AmmoType type = REGULAR);
  ~Phaser();
 public:
  void fire();
  void ejectClip();
  void changeType(AmmoType newType);
  void reload();
  void addAmmo(AmmoType type);
  int getCurrentAmmos() const;
 private:
  unsigned int		_maxAmmo;
  unsigned int		_curAmmo;
  Ammo		*_loaded;
  AmmoType	_type;
  Sounds	sounds;
  static const int Empty;
};

class Ammo
{
 public:
  Ammo(Phaser::AmmoType);
  ~Ammo();
 private:
  Phaser::AmmoType      _type;
  Ammo*                 _next;
 public:
  Ammo*			getNext();
  void			setNext(Ammo*);
  Phaser::AmmoType      getType();
  unsigned int          size();
  void			del();
};

#endif /* !PHASER_H_ */
