//
// AWeapon.cpp for aweapon in /home/baris_f/rendu/tek2/cpp_d10/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Fri Jan 13 10:47:44 2017 baris_f
// Last update Fri Jan 13 11:03:26 2017 baris_f
//

#include "AWeapon.hh"

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
  _name = name;
  _cost = apcost;
  _damage = damage;
}

AWeapon::~AWeapon(){

}

std::string const     AWeapon::getName() const{return (_name);}
int                   AWeapon::getAPCost() const{return (_cost);}
int                   AWeapon::getDamage() const{return (_damage);}
