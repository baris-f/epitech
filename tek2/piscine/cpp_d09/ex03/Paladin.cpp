//
// Paladin.cpp for pala in /home/baris_f/rendu/tek2/cpp_d09/ex03
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Thu Jan 12 15:13:54 2017 baris_f
// Last update Thu Jan 12 16:25:34 2017 baris_f
//

#include "Paladin.hh"

Paladin::Paladin(std::string name, int lvl) : Character(name, lvl),Warrior(name, lvl), Priest(name, lvl)
{
  _Stamina = 9;
  _Strengh = 10;
  _Intelligence = 10;
  _Spirit = 10;
  _Agility = 2;
  std::cout << "the light falls on " << getName() << std::endl;

}

Paladin::~Paladin(){

}

int	Paladin::CloseAttack(){
  return Warrior::CloseAttack();
}

int	Paladin::RangeAttack(){
  return Priest::RangeAttack();
}

void	Paladin::Heal(){
  return Priest::Heal();
}

int	Paladin::Intercept(){
  return Warrior::RangeAttack();
}

void	Paladin::RestorePower(){
  return Warrior::RestorePower();
}
