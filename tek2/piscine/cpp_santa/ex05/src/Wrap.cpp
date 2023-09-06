//
// Wrap.cpp for wrap in /home/baris_f/rendu/tek2/cpp_santa/ex03/src
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Sat Jan 14 00:57:22 2017 baris_f
// Last update Sun Jan 15 05:14:05 2017 baris_f
//

#include "Wrap.hh"

Wrap::Wrap(std::string const &name, std::string const &type, int wL, bool wrpd) : Object(name, type, wL, wrpd)
{
  _content = NULL;
}

Wrap::Wrap(Wrap const &other) : Object(other){

}

Wrap::~Wrap()
{

}

void	Wrap::wrapMeThat(Object* obj)
{
  if (_content != NULL)
    {
      std::cout << "This " << getType() << " is already containing something." << std::endl;
      return ;
    }
  else if (!obj)
    {
      std::cout << "I must have something to wrap !" << std::endl;
      return ;
    }
  else if (obj->getWrapped())
    {
      std::cout << "This" << obj->getType() <<" is already wrapped." << std::endl;
      return ;
    }
  /*  else if (_wrapLvl - 1 != obj->getWrapLvl())
  {
    std::cout << "I can't wrap a " << obj->getType() << "in a " << getType() << " !" << std::endl;
    return ;
    }*/
  obj->setWrapped(true);
  _content = obj;
}

void	Wrap::openMe()
{
  _opened = true;
}

void	Wrap::closeMe()
{
  _opened = true;
}

bool	Wrap::getOpened() {return (_opened);}
Object*	Wrap::takeMe()
{
  Object *tmp;

  if (getType() == "Box" && !_opened)
    {
      std::cerr << "The box isn't opened !" << std::endl;
      return (NULL);
    }
  tmp = _content;
  _content = NULL;
  return (tmp);
}
