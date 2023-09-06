//
// Lime.cpp for lime in /home/baris_f/rendu/tek2/cpp_d14m/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 17 16:10:38 2017 baris_f
// Last update Tue Jan 17 16:18:26 2017 baris_f
//


#include "Lime.h"

Lime::Lime() : Fruit("lime", 2)
{
}

std::string const &	Lime::getName() const
{
  return (_name);
}

Lime::~Lime()
{
}
