//
// PlasmaRifle.cpp for plasma in /home/baris_f/rendu/tek2/cpp_d10/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Fri Jan 13 10:56:41 2017 baris_f
// Last update Fri Jan 13 14:31:24 2017 baris_f
//

#include "PlasmaRifle.hh"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle", 5, 21)
{

}

PlasmaRifle::~PlasmaRifle()
{

}

void	PlasmaRifle::attack() const
{
  std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
