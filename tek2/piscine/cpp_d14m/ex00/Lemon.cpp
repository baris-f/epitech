//
// Lemon.cpp for lemon in /home/baris_f/rendu/tek2/cpp_d14m
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 17 10:09:04 2017 baris_f
// Last update Tue Jan 17 10:30:57 2017 baris_f
//

#include "Lemon.h"

Lemon::Lemon() : Fruit("lemon", 3)
{

}

Lemon::~Lemon()
{

}

std::string const &	Lemon::getName() const {return (_name);}
