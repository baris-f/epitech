//
// Character.cpp for charac in /home/baris_f/rendu/tek2/cpp_d10/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Fri Jan 13 13:56:46 2017 baris_f
// Last update Fri Jan 13 14:43:06 2017 baris_f
//

#include "Character.hh"
#include "PlasmaRifle.hh"
#include "PowerFist.hh"
#include "RadScorpion.hh"

Character::Character(std::string const & name)
{
  _name = name;
  _AP = 40;
  _weapon = NULL;
}

Character::~Character()
{

}

void	Character::recoverAP()
{
  if (_AP > 30)
    _AP = 40;
  _AP += 10;
}

void	Character::attack(AEnemy *enemy)
{
  if (_weapon == NULL || enemy == NULL || _weapon->getAPCost() > _AP)
    return ;
  _AP -= _weapon->getAPCost();
  std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
  _weapon->attack();
  enemy->takeDamage(_weapon->getDamage());
  if (enemy->getHP() <= 0)
    delete enemy;
}

void	Character::equip(AWeapon *weapon)
{
  _weapon = weapon;
}


std::string const	Character::getName() const{ return (_name);}
AWeapon*	Character::getWeapon() const{ return (_weapon);}
int	Character::getAP() const{ return (_AP);}

std::ostream &	operator<<(std::ostream & os, Character const & charac)
{
  if (charac.getWeapon() == NULL)
    os << charac.getName() << " has " << charac.getAP() << " AP and is unarmed" << std::endl;
  else
    os << charac.getName() << " has " << charac.getAP() << " AP and wields a " << charac.getWeapon()->getName() << std::endl;
  return (os);
}

/*
int main()
{
    Character* zaz = new Character("zaz");

    std::cout << *zaz;

    AEnemy* b = new RadScorpion();
    AWeapon* pr = new PlasmaRifle();
    AWeapon* pf = new PowerFist();

    zaz->equip(pr);
    std::cout << *zaz;
    zaz->equip(pf);

    zaz->attack(b);
    std::cout << *zaz;
    zaz->equip(pr);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;
    zaz->attack(b);
    std::cout << *zaz;

    return 0;
}
*/
