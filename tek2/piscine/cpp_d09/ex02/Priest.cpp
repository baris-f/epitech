//
// Mage.cpp for mage in /home/baris_f/rendu/tek2/cpp_d09/ex02
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Thu Jan 12 13:07:29 2017 baris_f
// Last update Thu Jan 12 17:55:21 2017 baris_f
//

#include "Priest.hh"

Priest::Priest(std::string name, int lvl) : Mage(name, lvl)
{
  _Stamina = 4;
  _Strengh = 4;
  _Intelligence = 42;
  _Spirit = 21;
  _Agility = 2;
  std::cout << getName() << " enters in the order" << std::endl;
}

Priest::~Priest(){

}

int     Priest::CloseAttack()
{
  if (getPower() < 10)
    {
      std::cout << getName() << " out of power" << std::endl;
      return (0);
    }
  setPower(getPower() - 10);
  std::cout << getName() << " uses a spirit explosion" << std::endl;
  Range = RANGE;
  return (10 + _Spirit);
}

void    Priest::Heal()
{
  if (getPower() < 10)
    {
      std::cout << getName() << " out of power" << std::endl;
      return ;
    }
  setPower(getPower() - 10);
  setPv(getPv() + 70);
  std::cout << getName() << " casts a little heal spell" << std::endl;
}
