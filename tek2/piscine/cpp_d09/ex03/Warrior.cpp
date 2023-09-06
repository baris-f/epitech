//
// Warrior.cpp for war in /home/baris_f/rendu/tek2/cpp_d09/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Thu Jan 12 10:29:54 2017 baris_f
// Last update Thu Jan 12 16:37:43 2017 baris_f
//

#include "Warrior.hh"

Warrior::Warrior(std::string name, int lvl) : Character(name, lvl)
{
  _weaponName = "hammer";
  _Stamina = 12;
  _Strengh = 12;
  _Intelligence = 6;
  _Spirit = 5;
  _Agility = 7;
  std::cout << "I'm "<< getName() << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

Warrior::~Warrior(){

}

int     Warrior::CloseAttack()
{
  if (getPower() < 30)
    {
      std::cout << getName() << " out of power" << std::endl;
      return (0);
    }
  setPower(getPower() - 30);
  std::cout << getName() << " strikes with his " << _weaponName << std::endl;
  return (20 + _Strengh);
}

int     Warrior::RangeAttack()
{
  if (getPower() < 10)
    {
      std::cout << getName() << " out of power" << std::endl;
      return (0);
    }
  setPower(getPower() - 10);
  std::cout << getName() << " intercepts" << std::endl;
  Range = CLOSE;
  return (0);
}

/*
int     main()
{
  Warrior _c("poney", 42);

  _c.TakeDamage(50);
  _c.TakeDamage(200);
  _c.TakeDamage(200);
  return (0);
}
*/
