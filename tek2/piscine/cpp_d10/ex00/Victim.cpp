//
// Sorcerer.cpp for sorcerer in /home/baris_f/rendu/tek2/cpp_d10/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Fri Jan 13 09:31:52 2017 baris_f
// Last update Fri Jan 13 10:29:24 2017 baris_f
//

#include "Victim.hh"

Victim::Victim(std::string name)
{
  _name = name;
  std::cout << "Some random victim called " << _name << " just popped !" << std::endl;
}

Victim::~Victim()
{
  std::cout << "Victim " << _name << " just died for no apparent reason !" << std::endl;
}

std::string const&	Victim::getName() const{ return (_name);}

void			Victim::getPolymorphed() const
{
  std::cout << _name << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream&   operator<<(std::ostream& os, Victim const& victim)
{
  os << "I'm " << victim.getName() << " and i like otters !" << std::endl;
  return (os);
}
