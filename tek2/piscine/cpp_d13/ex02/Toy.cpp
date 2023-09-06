//
// Toy.cpp for toy in /home/baris_f/rendu/tek2/cpp_d13/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Mon Jan 16 10:32:15 2017 baris_f
// Last update Mon Jan 16 19:28:45 2017 baris_f
//

#include "Toy.h"
#include "Buzz.h"
#include "Woody.h"

Toy::Toy()
{
  _type = BASIC_TOY;
  _name = "toy";
}

Toy::Toy(const Toy &other)
{
  _type = other.getType();
  _name = other.getName();
  _picture = other._picture;
}

Toy::Toy(Toy::ToyType type, std::string name, std::string filename)
{
  _type = type;
  _name = name;
  _picture.getPictureFromFile(filename);
}

Toy::~Toy()
{

}

Toy &	Toy::operator=(const Toy &other)
{
  _type = other.getType();
  _name = other.getName();
  _picture = other._picture;
  return (*this);
}

Toy::ToyType			Toy::getType() const{ return (_type);}
std::string const	Toy::getName() const{ return (_name);}
void			Toy::setName(std::string name) { _name = name;}
std::string const	Toy::getAscii() const{ return (_picture.data);}
bool			Toy::setAscii(std::string file) { return(_picture.getPictureFromFile(file));}

/*
int main()
{
  Buzz toto("enculé");
  Woody ET("green", "./alien.txt");

  toto.setName("TOTO !");
  if (toto.getType() == Toy::BUZZ)
    std::cout << "basic toy: " << toto.getName() << std::endl << toto.getAscii() << std::endl;
  if (ET.getType() == Toy::WOODY)
    std::cout << "this alien is: " << ET.getName() << std::endl << ET.getAscii() << std::endl;
  return 1337;
}
*/
