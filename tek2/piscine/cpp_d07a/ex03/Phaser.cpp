//
// Phaser.cpp for phaser in /home/baris_f/rendu/tek2/cpp_d07a/ex03
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 10 20:59:26 2017 baris_f
// Last update Wed Jan 11 08:54:23 2017 baris_f
//

#include "Phaser.h"

const int Phaser::Empty = 0;

Phaser::Phaser(int maxAmmo, AmmoType type)
{
  _maxAmmo = maxAmmo;
  _type = type;
  _loaded = NULL;
  for (unsigned int i = 0; i < _maxAmmo; i++)
    addAmmo(_type);
}

Phaser::~Phaser(){
  ejectClip();
}

void	Phaser::fire()
{
  if (_loaded == NULL)
    {
      std::cout << "\tClip empty, please reload" << std::endl;
      return ;
    }
  if (_type == REGULAR)
    std::cout << sounds.Regular << std::endl;
  else if (_type == PLASMA)
    std::cout << sounds.Plasma << std::endl;
  else if (_type == ROCKET)
  std::cout << sounds.Rocket << std::endl;
  Ammo	*tmp;

  tmp = _loaded;
  _loaded = _loaded->getNext();
  delete tmp;
}

void	Phaser::ejectClip()
{
  if (_loaded != NULL)
    {
      _loaded->del();
      _loaded = NULL;
    }
}

void	Phaser::changeType(AmmoType newType)
{
  _type = newType;
  std::cout << "Switching ammo to type :";
    if (_type == REGULAR)
    std::cout << "regular" << std::endl;
  else if (_type == PLASMA)
    std::cout << "plasma" << std::endl;
  else if (_type == ROCKET)
    std::cout << "regular" << std::endl;
}

void	Phaser::reload()
{
  std::cout << "Reloading..." << std::endl;
  for (unsigned int i = 0; i < _maxAmmo - _loaded->size(); i++)
    addAmmo(_type);
}

void	Phaser::addAmmo(AmmoType type)
{
  Ammo	*mun = new Ammo(_type);

  if (_loaded == NULL && _maxAmmo >= 1)
    {
      _type = type;
      _loaded = mun;
    }
  else if (_loaded->size() == _maxAmmo)
    std::cout << "\tClip full" << std::endl;
  else
    {
      Ammo *tmp;
      _type = type;
      for (tmp = _loaded; tmp->getNext(); tmp = tmp->getNext());
      tmp->setNext(mun);
    }
}

int	Phaser::getCurrentAmmos() const
{
  if (_loaded == NULL)
    return (0);
  else
    return ((int)(_loaded->size()));
}

Ammo::Ammo(Phaser::AmmoType type)
{
  _type = type;
  _next = NULL;
}

Ammo::~Ammo(){
}

Phaser::AmmoType	Ammo::getType(){
  return (_type);
}

Ammo*		Ammo::getNext(){
  return (_next);
}

void		Ammo::setNext(Ammo* next){
  _next = next;
}

unsigned int	Ammo::size(){
  if (_next == NULL)
    return (1);
  else
    return (getNext()->size() + 1);
}

void		Ammo::del(){
  if (_next)
    return (getNext()->del());
  delete this;
}

/*
const std::string Sounds::Regular = "Pew";
const std::string Sounds::Plasma = "Zup";
const std::string Sounds::Rocket = "Booooooom";

int main()
{
  Phaser p(5, Phaser::ROCKET);
  p.fire();
  p.reload();

  std::cout << "Firing all ammunitions" << std::endl;
  while (p.getCurrentAmmos() > 0)
    p.fire();
  return 0;
}
*/
