//
// Mage.cpp for mage in /home/baris_f/rendu/tek2/cpp_d09/ex02
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Thu Jan 12 13:07:29 2017 baris_f
// Last update Thu Jan 12 13:18:14 2017 baris_f
//

#include "Mage.hh"

Mage::Mage(std::string name, int lvl) : Character(name, lvl)
{
  _Stamina = 6;
  _Strengh = 6;
  _Intelligence = 12;
  _Spirit = 11;
  _Agility = 7;
  std::cout << getName() << " teleported" << std::endl;
}

Mage::~Mage(){

}

int     Mage::CloseAttack()
{
  if (getPower() < 10)
    {
      std::cout << getName() << " out of power" << std::endl;
      return (0);
    }
  setPower(getPower() - 10);
  std::cout << getName() << " blinks" << std::endl;
  Range = RANGE;
  return (0);
}

int     Mage::RangeAttack()
{
  if (getPower() < 25)
    {
      std::cout << getName() << " out of power" << std::endl;
      return (0);
    }
  setPower(getPower() - 25);
  std::cout << getName() << " launches a fire ball" << std::endl;
  Range = CLOSE;
  return (20 + _Spirit);
}

void	Mage::RestorePower()
{
  setPower(getPower() + 50 + _Intelligence);
  std::cout << getName() << " takes a mana potion" << std::endl;
}
