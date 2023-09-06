/*
** sickkoalalist.c for list in /home/baris_f/rendu/tek2/cpp_d06/ex05
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Mon Jan  9 17:46:09 2017 baris_f
// Last update Mon Jan  9 22:51:13 2017 baris_f
*/

#include <cstdio>
#include "sickkoalalist.h"

SickKoalaList::SickKoalaList(SickKoala *ptkoala)
{
  koala = ptkoala;
  next = NULL;
}

SickKoalaList::~SickKoalaList()
{
  koala = NULL;
}

bool	SickKoalaList::isEnd()
{
  if (next)
    return (false);
  return (true);
}

void	SickKoalaList::append(SickKoalaList *newk)
{
  if (!isEnd())
    next->append(newk);
  else
    next = newk;
}

SickKoala	*SickKoalaList::getFromName(std::string kname)
{
  if (koala && koala->getName() == kname)
    return (this->koala);
  else if (!isEnd())
    return (next->getFromName(kname));
  else
    return (NULL);
}

SickKoalaList	*SickKoalaList::remove(SickKoalaList *k)
{
  if (next != k && !isEnd())
    next->remove(k);
  else
    {
      next = next->next;
      k->next = NULL;
    }
  return (this);
}

SickKoalaList	*SickKoalaList::removeFromName(std::string kname)
{
  if (next->koala->getName() != kname && !isEnd())
    next->removeFromName(kname);
  else
    {
      SickKoalaList *tmp = next;
      next = next->next;
      tmp->next = NULL;
    }
  return (this);
}

void		SickKoalaList::dump()
{
  std::cout << "Liste des patients: ";
  for(SickKoalaList* tmp = this; tmp; tmp = tmp->next)
    {
      if (tmp != this)
      	std::cout << ", ";

      if (tmp->koala == NULL)
	std::cout << "[NULL]";
      else
	std::cout << tmp->koala->getName();
    }
  std::cout << "." << std::endl;
}

SickKoala	*SickKoalaList::getContent()
{
  return (koala);
}

SickKoalaList	*SickKoalaList::getNext()
{
  return (next);
}
