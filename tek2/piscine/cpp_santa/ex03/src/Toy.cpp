//
// Toy.cpp for  in /home/grandm_a/cpp_d10/cpp_santa/ex1
//
// Made by grandm_a
// Login   <corentin.grandmaire@epitech.eu>
//
// Started on  Sat Jan 14 00:50:07 2017 grandm_a
// Last update Sun Jan 15 01:56:15 2017 baris_f
//

#include "Toy.hh"

Toy::Toy(std::string const& name, std::string type) :
  Object(name, type)
{

}

Toy::Toy(Toy const &other): Object(other) {
}

Toy::~Toy()
{
}
