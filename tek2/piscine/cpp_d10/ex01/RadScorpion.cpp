//
// AWeapon.cpp for aweapon in /home/baris_f/rendu/tek2/cpp_d10/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Fri Jan 13 10:47:44 2017 baris_f
// Last update Fri Jan 13 13:49:06 2017 baris_f
//

#include "RadScorpion.hh"

RadScorpion::RadScorpion() : AEnemy(80, "RadScorpion")
{
  std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion(){
  std::cout << "* SPROTCH *" << std::endl;
}
