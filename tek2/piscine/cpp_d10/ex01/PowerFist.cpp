//
// PowerFist.cpp for plasma in /home/baris_f/rendu/tek2/cpp_d10/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Fri Jan 13 10:56:41 2017 baris_f
// Last update Fri Jan 13 14:31:41 2017 baris_f
//

#include "PowerFist.hh"

PowerFist::PowerFist() : AWeapon("Power Fist", 8, 50)
{

}

PowerFist::~PowerFist()
{

}

void	PowerFist::attack() const
{
  std::cout << "* pschhh... SBAM! *" << std::endl;
}
