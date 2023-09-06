//
// GiftPaper.cpp for gift in /home/baris_f/rendu/tek2/cpp_santa/ex03/src
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Sat Jan 14 02:11:24 2017 baris_f
// Last update Sun Jan 15 01:49:29 2017 baris_f
//

#include "GiftPaper.hh"

GiftPaper::GiftPaper(std::string name) : Wrap(name, "GiftPaper", 2, false)
{

}

GiftPaper::~GiftPaper()
{

}

void    GiftPaper::wrapMeThat(Box* obj)
{
  if (obj->getOpened() == false)
    {
      std::cout << "I can't wrap a closed Box !" << std::endl;
      return;
    }
  Wrap::wrapMeThat(obj);
}
