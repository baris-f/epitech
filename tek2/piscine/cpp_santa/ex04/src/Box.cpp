//
// Box.cpp for box in /home/baris_f/rendu/tek2/cpp_santa/ex03/src
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Sat Jan 14 01:52:52 2017 baris_f
// Last update Sun Jan 15 01:48:55 2017 baris_f
//


#include "Box.hh"

Box::Box(std::string name) : Wrap(name, "Box", 1, false)
{

}

Box::~Box()
{

}

void	Box::wrapMeThat(Object* obj)
{
  if (_opened == false)
    {
      std::cout << "I can't wrap in a closed Box !" << std::endl;
      return;
    }
  Wrap::wrapMeThat(obj);
}
