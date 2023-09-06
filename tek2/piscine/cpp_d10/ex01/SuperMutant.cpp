//
// AWeapon.cpp for aweapon in /home/baris_f/rendu/tek2/cpp_d10/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Fri Jan 13 10:47:44 2017 baris_f
// Last update Fri Jan 13 13:44:44 2017 baris_f
//

#include "SuperMutant.hh"

SuperMutant::SuperMutant() : AEnemy(170, "Super Mutant")
{
  std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::~SuperMutant(){
  std::cout << "Aaargh ..." << std::endl;
}

void                    SuperMutant::takeDamage(int dmg)
{
  dmg -= 3;
  if (dmg <= 0)
    return ;
  _hp -= dmg;
}
