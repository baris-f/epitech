//
// Buzz.cpp for buzz in /home/baris_f/rendu/tek2/cpp_d13/ex02
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Mon Jan 16 19:18:48 2017 baris_f
// Last update Mon Jan 16 22:45:46 2017 baris_f
//

#include "Buzz.h"

Buzz::Buzz(std::string name, std::string filename) : Toy(BUZZ, name, filename)
{

}

Buzz::~Buzz()
{

}

void    Buzz::speak(std::string str)
{
  std::cout << "BUZZ: ";
  Toy::speak(str);
}

bool	Buzz::speak_es(std::string str)
{
  std::cout << "BUZZ: " << _name << "senorita \"" << str << "\" senorita" << std::endl;
  return (true);
}
