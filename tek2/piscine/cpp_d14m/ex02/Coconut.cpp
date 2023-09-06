//
// Coconut.cpp for coco in /home/baris_f/rendu/tek2/cpp_d14m/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 17 16:09:19 2017 baris_f
// Last update Tue Jan 17 16:16:35 2017 baris_f
//

#include "Coconut.h"

Coconut::Coconut() : Fruit("Coconut", 2)
{
}

std::string const &	Coconut::getName() const
{
  return (_name);
}

Coconut::~Coconut()
{
}
