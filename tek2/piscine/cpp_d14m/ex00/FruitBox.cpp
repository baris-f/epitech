//
// FruitBox.cpp for fruitbox in /home/baris_f/rendu/tek2/cpp_d14m
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 17 10:59:36 2017 baris_f
// Last update Tue Jan 17 14:53:17 2017 baris_f
//

#include "FruitBox.h"
#include "FruitNode.h"

FruitBox::FruitBox(int size)
{
  _head = NULL;
  _msize = size;
}

FruitBox::~FruitBox()
{

}

int	FruitBox::nbFruits(){return (_size);}
FruitNode*	FruitBox::head(){return (_head);}

bool	FruitBox::putFruit(Fruit *f)
{
  FruitNode*	tmp;
  FruitNode*	newf;

  for(tmp = _head; tmp && tmp->_next; tmp = tmp->_next)
    if (tmp->_fruit == f || _size >= _msize)
      return (false);
  newf = new FruitNode;
  newf->_next = NULL;
  newf->_fruit = f;
  _size++;
  if (tmp)
    tmp->_next = newf;
  else
    _head = newf;
  return (true);
}

Fruit*	FruitBox::pickFruit()
{
  Fruit*	fruit;
  FruitNode*	tmp;

  if (!_head)
    return (NULL);
  fruit = _head->_fruit;
  tmp = _head;
  _head = _head->_next;
  delete tmp;
  return (fruit);
}

void	FruitBox::disp()
{
  FruitNode*	tmp;

  for(tmp = _head; tmp; tmp = tmp->_next)
    std::cout << tmp->_fruit->getName() << std::endl;
  std::cout << "################" << std::endl;
}
