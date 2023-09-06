/*
** sickkoalalist.c for list in /home/baris_f/rendu/tek2/cpp_d06/ex05
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Mon Jan  9 17:46:09 2017 baris_f
// Last update Tue Jan 10 08:56:17 2017 baris_f
*/

#include <cstdio>
#include "koalanurselist.h"

KoalaNurseList::KoalaNurseList(KoalaNurse *ptkoala)
{
  koala = ptkoala;
  next = NULL;
}

KoalaNurseList::~KoalaNurseList()
{
  koala = NULL;
}

bool	KoalaNurseList::isEnd()
{
  if (next)
    return (false);
  return (true);
}

void	KoalaNurseList::append(KoalaNurseList *newk)
{
  if (!isEnd())
    next->append(newk);
  else
    next = newk;
}

KoalaNurse	*KoalaNurseList::getFromID(int kID)
{
  if (koala && koala->getID() == kID)
    return (this->koala);
  else if (!isEnd())
    return (next->getFromID(kID));
  else
    return (NULL);
}

KoalaNurseList	*KoalaNurseList::remove(KoalaNurseList *k)
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

KoalaNurseList	*KoalaNurseList::removeFromID(int kID)
{
  if (next->koala->getID() != kID && !isEnd())
    next->removeFromID(kID);
  else
    {
      KoalaNurseList *tmp = next;
      next = next->next;
      tmp->next = NULL;
    }
  return (this);
}

void		KoalaNurseList::dump()
{
  std::cout << "Liste des infirmieres: ";
  for(KoalaNurseList* tmp = this; tmp; tmp = tmp->next)
    {
      if (tmp != this)
      	std::cout << ", ";
      if (tmp->koala == NULL)
	std::cout << "[NULL]";
      else
	std::cout << tmp->koala->getID();
    }
  std::cout << "." << std::endl;
}

KoalaNurse	*KoalaNurseList::getContent()
{
  return (koala);
}

KoalaNurseList	*KoalaNurseList::getNext()
{
  return (next);
}
