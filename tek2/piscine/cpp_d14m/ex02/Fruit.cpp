//
// Fruit.cpp for fruit in /home/baris_f/rendu/tek2/cpp_d14m
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 17 09:58:20 2017 baris_f
// Last update Tue Jan 17 13:50:32 2017 baris_f
//

#include "Fruit.h"

Fruit::Fruit(std::string name, int vit)
{
  _name = name;
  _vitamins = vit;
}

Fruit::Fruit(const Fruit &other)
{
  _name = other.getName();
  _vitamins = other.getVitamins();
}

Fruit::~Fruit()
{

}

Fruit &	Fruit::operator=(const Fruit &other)
{
  _name = other.getName();
  _vitamins = other.getVitamins();
  return (*this);
}

//std::string const &	Fruit::getName() const{return (_name);}
int			Fruit::getVitamins() const {return (_vitamins);}
