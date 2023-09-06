//
// AWeapon.cpp for aweapon in /home/baris_f/rendu/tek2/cpp_d10/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Fri Jan 13 10:47:44 2017 baris_f
// Last update Fri Jan 13 14:15:41 2017 baris_f
//

#include "AEnemy.hh"

AEnemy::AEnemy(int hp, std::string const & type)
{
  _hp = hp;
  _type = type;
}

AEnemy::~AEnemy(){

}

std::string const	AEnemy::getType() const{return (_type);}
int			AEnemy::getHP() const{return (_hp);}

void			AEnemy::takeDamage(int dmg)
{
  if (dmg <= 0)
    return ;
  _hp -= dmg;
}
