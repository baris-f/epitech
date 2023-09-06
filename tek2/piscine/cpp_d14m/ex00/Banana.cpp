//
// Banana.cpp for banana in /home/baris_f/rendu/tek2/cpp_d14m
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 17 10:13:11 2017 baris_f
// Last update Tue Jan 17 10:29:02 2017 baris_f
//

#include "Banana.h"

Banana::Banana() : Fruit("banana", 5)
{

}

Banana::~Banana()
{

}

std::string const &	Banana::getName() const {return (_name);}
