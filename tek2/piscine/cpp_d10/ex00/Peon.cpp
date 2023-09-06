//
// Sorcerer.cpp for sorcerer in /home/baris_f/rendu/tek2/cpp_d10/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Fri Jan 13 09:31:52 2017 baris_f
// Last update Fri Jan 13 10:35:33 2017 baris_f
//

#include "Sorcerer.hh"
#include "Peon.hh"

Peon::Peon(std::string name) : Victim(name)
{
  _name = name;
  std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
  std::cout << "Bleuark..." << std::endl;
}

void			Peon::getPolymorphed() const
{
  std::cout << _name << " has been turned into a pink pony !" << std::endl;
}

/*
int main()
{
    Sorcerer robert("Robert", "the Magnificent");
    Victim jim("Jimmy");
    Peon joe("Joe");

    std::cout << robert << jim << joe;
    robert.polymorph(jim);
    robert.polymorph(joe);

    return 0;
}
*/
