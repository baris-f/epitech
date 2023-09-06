//
// TablePePeNoel.cpp for  in /home/fus/taff/cpp_santa/ex4/src
//
// Made by Gaspard Thirion
// Login   <thirio_b@epitech.net>
//
// Started on  Fri Jan 13 23:46:36 2017 Gaspard Thirion
// Last update Sun Jan 15 05:29:30 2017 baris_f
//

#include "TablePePeNoel.hh"
#include "Teddy.hh"
#include "LittlePony.hh"

//********
//maillon
//********
maillon::maillon(Object* obj, maillon* next)
  : _next(next)
{
  _object = obj;
}

Object*		maillon::getObject()	const{ return (_object);	}
maillon*	maillon::getNext()	const{ return (_next);	}

void	maillon::setNext(maillon* m)	{ _next = m;		}

// Object*	maillon::remove()
// {
// }

std::ostream&	operator<<(std::ostream& o, maillon& m)
{
  return (o << m.getObject()->getName() << std::endl);
}

//**************
//TablePePeNoel
//**************
TablePePeNoel::TablePePeNoel()
  : _size(0), _list(NULL)
{
  addToy();
  addToy();
  //  addToy();
}

Object*		TablePePeNoel::Take(std::string obj)
{
  maillon*	tmp;
  Object*	tmpObject;

  for (tmp = _list; tmp; tmp = tmp->getNext())
    if (tmp && tmp->getNext() && tmp->getNext()->getObject() &&
	tmp->getNext()->getObject()->getType() == obj)
      {
	tmpObject = tmp->getNext()->getObject();
	tmp->setNext(tmp->getNext()->getNext());
	tmpObject->isTaken();
	return (tmpObject);
      }
  return (NULL);
}

std::string*	TablePePeNoel::Look()
{
  maillon*	tmp;
  std::string*	ret = new std::string[11];
  int		i = -1;

  for (tmp = _list; tmp; tmp = tmp->getNext())
    {
      ret[++i] = tmp->getObject()->getType();
    }
  ret[++i] = "";
  return (ret);
}

int		TablePePeNoel::getSize(){
  maillon *tmp = _list;
  int i = 0;

  while(tmp && tmp->getNext()) {
    tmp = tmp->getNext();
    i++;
  }
  return ++i;
}

void		TablePePeNoel::Put(Object* obj)
{
  if (getSize() < 10)
    {
      maillon	*m = new maillon(obj, _list);
      _list = m;
      _size += 1;
    }
  else {
    std::cout << "The table explodes, the elf dies in the wake" << std::endl;
    std::exit(-1);
  }
}

void		TablePePeNoel::addToy()
{
  srand(time(NULL));
  if ((random() % 2) == 0)
    {
      Teddy *ted = new Teddy("bisounous");
      Put(ted);
    }
  else
    {
      LittlePony *pony = new LittlePony("gay pony");
      Put(pony);
    }
}
