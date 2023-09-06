//
// LittlePony.cpp for  in /home/grandm_a/cpp_d10/cpp_santa/ex1
// 
// Made by grandm_a
// Login   <corentin.grandmaire@epitech.eu>
// 
// Started on  Sat Jan 14 02:04:49 2017 grandm_a
// Last update Sat Jan 14 14:05:25 2017 grandm_a
//

#include "LittlePony.hh"

LittlePony::LittlePony(std::string const& name) :
  Toy(name, "LittlePony")
{
}

LittlePony::~LittlePony()
{
}

void	LittlePony::isTaken()
{
  std::cout << "yo man" << std::endl;
  Object::isTaken();
}

