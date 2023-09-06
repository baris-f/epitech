//
// Character.cpp for  in /home/baris_f/rendu/tek2/cpp_d09/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Thu Jan 12 09:28:09 2017 baris_f
// Last update Thu Jan 12 17:56:23 2017 baris_f
//

#include "Character.hh"
#include "Priest.hh"

Character::Character(std::string const name, int lvl)
{
  _name = name;
  _lvl = lvl;
  _Pv = 100;
  _Power = 100;
  _Strengh = 5;
  _Stamina = 5;
  _Intelligence = 5;
  _Spirit = 5;
  _Agility = 5;
  Range = CLOSE;
  std::cout << getName() << " Created" << std::endl;
}

Character::~Character()
{

}

std::string const&	Character::getName() const { return (_name);}
int			Character::getLvl() const { return (_lvl);}
int			Character::getPv() const { return (_Pv);}
void			Character::setPv(int Pv){
  _Pv = Pv;
  if (_Pv > 100)
    _Pv = 100;
  if (_Pv <= 0)
    std::cout << getName() << " out of combat" << std::endl;
}
int			Character::getPower() const{ return (_Power);}
void			Character::setPower(int Power){
  _Power = Power;
  if (_Power > 100)
    _Power = 100;
}

int	Character::CloseAttack()
{
  if (getPower() < 10)
    {
      std::cout << getName() << " out of power" << std::endl;
      return (0);
    }
  setPower(getPower() - 10);
  std::cout << getName() << " strikes with a wood stick" << std::endl;
  return (10 + _Strengh);
}

int	Character::RangeAttack()
{
  if (getPower() < 10)
    {
      std::cout << getName() << " out of power" << std::endl;
      return (0);
    }
  setPower(getPower() - 10);
  std::cout << getName() << " launches a stone" << std::endl;
  return (5 + _Strengh);
}

void	Character::Heal()
{
  setPv(getPv() + 50);
  std::cout << getName() << " takes a potion" << std::endl;
}

void	Character::RestorePower()
{
  setPower(100);
  std::cout << getName() << " eats" << std::endl;
}

void	Character::TakeDamage(int _damage)
{
  setPv(getPv() - _damage);
  if (getPv() <= 0)
    return ;
  std::cout << getName() << " takes " << _damage << " damage" << std::endl;
}
/*
int	main()
{
  Priest _c("poney", 42);

  _c.TakeDamage(50);
  _c.TakeDamage(200);
  _c.TakeDamage(200);
  return (0);
}
*/
