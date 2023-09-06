/*
** sickkoalalist.c for list in /home/baris_f/rendu/tek2/cpp_d06/ex05
**
** Made by baris_f
** Login   <florent.baris@epitech.eu>
**
** Started on  Mon Jan  9 17:46:09 2017 baris_f
// Last update Mon Jan  9 22:44:28 2017 baris_f
*/

#include <cstdio>
#include "koaladoctorlist.h"

KoalaDoctorList::KoalaDoctorList(KoalaDoctor *ptkoala)
{
  koala = ptkoala;
  next = NULL;
}

KoalaDoctorList::~KoalaDoctorList()
{
  koala = NULL;
}

bool	KoalaDoctorList::isEnd()
{
  if (next)
    return (false);
  return (true);
}

void	KoalaDoctorList::append(KoalaDoctorList *newk)
{
  if (!isEnd())
    next->append(newk);
  else
    next = newk;
}

KoalaDoctor	*KoalaDoctorList::getFromName(std::string kname)
{
  if (koala && koala->getName() == kname)
    return (this->koala);
  else if (!isEnd())
    return (next->getFromName(kname));
  else
    return (NULL);
}

KoalaDoctorList	*KoalaDoctorList::remove(KoalaDoctorList *k)
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

KoalaDoctorList	*KoalaDoctorList::removeFromName(std::string kname)
{
  if (next->koala->getName() != kname && !isEnd())
    next->removeFromName(kname);
  else
    {
      KoalaDoctorList *tmp = next;
      next = next->next;
      tmp->next = NULL;
    }
  return (this);
}

void		KoalaDoctorList::dump()
{
  std::cout << "Liste des medecins: ";
  for(KoalaDoctorList* tmp = this; tmp; tmp = tmp->next)
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

KoalaDoctor	*KoalaDoctorList::getContent()
{
  return (koala);
}

KoalaDoctorList	*KoalaDoctorList::getNext()
{
  return (next);
}
