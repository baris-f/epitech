//
// Toy.cpp for toy in /home/baris_f/rendu/tek2/cpp_d13/ex00
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Mon Jan 16 10:32:15 2017 baris_f
// Last update Tue Jan 17 09:00:40 2017 baris_f
//

#include "Toy.h"
#include "Buzz.h"
#include "Woody.h"

//Error

Toy::Error::Error(){
  type = UNKNOWN;
}

Toy::Error::~Error(){

}

std::string	&Toy::Error::what()
{
  return (_what);
}

std::string	&Toy::Error::where()
{
  return (_where);
}

//Toy

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

bool	Toy::speak_es(std::string str)
{
  error._what = "wrong mode";
  error._where = "speak_es";
  (void)str;
  return (false);
}

Toy::Error &	Toy::getLastError()
{
  Error *err = new Error;

  if (error._where == "speak_es")
    err->type = Error::SPEAK;
  else if (error._where == "setAscii")
    err->type = Error::PICTURE;
  else
    err->type = Error::UNKNOWN;
  return(*err);
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
bool			Toy::setAscii(std::string file) {
  bool tmp;

  tmp = _picture.getPictureFromFile(file);

  if (tmp == false)
    {
      error._where = "setAscii";
      error._what = "bad new illustration";
    }
  return (tmp);
}
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


int main()
{
  Woody w("wood");

  if (w.setAscii("file_who_does_not_exist.txt") == false)
    {
      Toy::Error e = w.getLastError();
      if (e.type == Toy::Error::PICTURE)
	{
	  std::cout << "Error in " << e.where()
		    << ": " << e.what() << std::endl;
	}
    }
  if (w.speak_es("Woody does not have spanish mode") == false)
    {
      Toy::Error e = w.getLastError();
      if (e.type == Toy::Error::SPEAK)
	{
	  std::cout << "Error in " << e.where()
		    << ": " << e.what() << std::endl;
	}
    }
}
