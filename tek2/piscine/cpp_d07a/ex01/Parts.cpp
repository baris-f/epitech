//
// Part.cpp for part in /home/baris_f/rendu/tek2/cpp_d07a/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 10 17:58:46 2017 baris_f
// Last update Tue Jan 10 23:13:20 2017 baris_f
//

#include "Parts.h"

Arms::Arms(std::string serial, bool functionnal)
{
  _serial = serial;
  _functionnal = functionnal;
}

Arms::~Arms(){

}

bool	Arms::isFunctionnal() const{
  return (_functionnal);
}

std::string	Arms::serial() const{
  return (_serial);
}

void	Arms::informations() const{
  std::cout << "\t[Parts] Arms " << serial() << " status : ";
  if (isFunctionnal())
    std::cout << "OK" << std::endl;
  else
    std::cout << "KO" << std::endl;
}

//Legs

Legs::Legs(std::string serial, bool functionnal)
{
  _serial = serial;
  _functionnal = functionnal;
}

Legs::~Legs(){

}

bool	Legs::isFunctionnal() const{
  return (_functionnal);
}

std::string	Legs::serial() const{
  return (_serial);
}

void	Legs::informations() const{
  std::cout << "\t[Parts] Legs " << serial() << " status : ";
  if (isFunctionnal())
    std::cout << "OK" << std::endl;
  else
    std::cout << "KO" << std::endl;
}

//Head

Head::Head(std::string serial, bool functionnal)
{
  _serial = serial;
  _functionnal = functionnal;
}

Head::~Head(){

}

bool	Head::isFunctionnal() const{
  return (_functionnal);
}

std::string	Head::serial() const{
  return (_serial);
}

void	Head::informations() const{
  std::cout << "\t[Parts] Head " << serial() << " status : ";
  if (isFunctionnal())
    std::cout << "OK" << std::endl;
  else
    std::cout << "KO" << std::endl;
}
