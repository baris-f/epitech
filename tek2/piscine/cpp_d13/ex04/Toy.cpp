//
// Toy.cpp for toy in /home/baris_f/rendu/tek2/cpp_d13/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Mon Jan 16 10:32:15 2017 baris_f
// Last update Mon Jan 16 22:19:32 2017 baris_f
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

void	Toy::speak(std::string str)
{
  std::cout << _name << " \"" << str << "\"" << std::endl;
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
void			Toy::setAsciiStr(std::string str) { _picture.data = str;}

std::ostream &	operator<<(std::ostream& os, const Toy &toy)
{
  os << toy.getName() << std::endl << toy.getAscii() << std::endl;
  return (os);
}

Toy &		operator<<(Toy &toy, std::string str)
{
  toy.setAsciiStr(str);
  return (toy);
}

/*
int main()
{
    Toy a(Toy::BASIC_TOY, "REX", "rex.txt");

    std::cout << a;
    a << "\\o/";
    std::cout << a;
}
*/
