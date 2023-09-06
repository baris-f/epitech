//
// Paladin.cpp for pala in /home/baris_f/rendu/tek2/cpp_d09/ex03
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Thu Jan 12 15:13:54 2017 baris_f
// Last update Thu Jan 12 18:06:29 2017 baris_f
//

#include "Hunter.hh"

Hunter::Hunter(std::string name, int lvl) : Character(name, lvl),Warrior(name, lvl)
{
  _weaponName = "sword";
  _Stamina = 9;
  _Strengh = 9;
  _Intelligence = 5;
  _Spirit = 6;
  _Agility = 24;
  std::cout << getName() << " is born from a tree" << std::endl;

}

Hunter::~Hunter(){

}

int	Hunter::CloseAttack(){
  return Warrior::CloseAttack();
}

int	Hunter::RangeAttack(){
  if (getPower() < 25)
    {
      std::cout << getName() << " out of power" << std::endl;
      return (0);
    }
  setPower(getPower() - 25);
  std::cout << getName() << " uses his bow" << std::endl;
  return (20 + _Agility);
}

void	Hunter::RestorePower(){
  setPower(100);
  std::cout << getName() << " meditates" << std::endl;
}
/*
int	main()
{
  Hunter ("fdp", 40);
}
*/
