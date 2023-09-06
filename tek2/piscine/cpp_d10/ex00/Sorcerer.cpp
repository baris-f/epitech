//
// Sorcerer.cpp for sorcerer in /home/baris_f/rendu/tek2/cpp_d10/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Fri Jan 13 09:31:52 2017 baris_f
// Last update Fri Jan 13 10:29:11 2017 baris_f
//

#include "Sorcerer.hh"

Sorcerer::Sorcerer(std::string name, std::string title)
{
  _name = name;
  _title = title;
  std::cout << _name << ", " << _title << ", is born !" << std::endl;
}

Sorcerer::~Sorcerer()
{
  std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same !" << std::endl;
}

std::string const&	Sorcerer::getName() const{ return (_name);}
std::string const&	Sorcerer::getTitle() const{ return (_title);}

void			Sorcerer::polymorph(Victim const& victim)
{
  victim.getPolymorphed();
}

std::ostream&   operator<<(std::ostream& os, Sorcerer const& sorcerer)
{
  os << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
  return (os);
}
