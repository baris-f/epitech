//
// Object.hh for  in /home/grandm_a/cpp_d10/cpp_santa/ex1
//
// Made by grandm_a
// Login   <corentin.grandmaire@epitech.eu>
//
// Started on  Sat Jan 14 00:27:47 2017 grandm_a
// Last update Sat Jan 14 17:55:11 2017 baris_f
//

#ifndef toy_h
#define toy_h

#include <string>
#include <iostream>
#include "Object.hh"

class Toy : virtual public Object
{

public:
  Toy(std::string const& name, std::string type);
  ~Toy();

};

#endif
