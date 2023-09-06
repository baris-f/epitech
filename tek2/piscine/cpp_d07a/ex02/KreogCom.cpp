//
// KreogCom.cpp for kreok in /home/baris_f/rendu/tek2/cpp_d07a/ex02
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 10 19:47:57 2017 baris_f
// Last update Wed Jan 11 09:35:59 2017 baris_f
//


#include "KreogCom.h"

KreogCom::KreogCom(int x, int y, int serial)
{
  _x = x;
  _y = y;
  _serial = serial;
  _next = NULL;
  std::cout << "KreogCom " << _serial << " initialised" << std::endl;
}

KreogCom::~KreogCom(){
  std::cout << "KreogCom " << _serial << " shutting down" << std::endl;
}

void	KreogCom::addCom(int x, int y, int serial)
{
  KreogCom	*newk = new KreogCom(x, y, serial);

  if (_next)
    newk->_next = _next;
  _next = newk;
}

KreogCom	*KreogCom::getCom()
{
  if (_next == NULL)
    return (0);
  return (_next);
}

void		KreogCom::removeCom()
{
  KreogCom	*tmp;

  if (!_next)
    return ;
  tmp = _next;
  _next = _next->_next;
}

void		KreogCom::ping() const
{
  std::cout << "KreogCom " << _serial << " currently at " << _x << " " << _y << std::endl;
}

void		KreogCom::locateSquad() const
{
  if (_next)
    _next->locateSquad2();
  ping();
}

void		KreogCom::locateSquad2()
{
  ping();
  if (_next)
    _next->locateSquad2();
}
/*
int main()
{
    KreogCom k(42, 42, 101010);

    k.addCom(56, 25, 65);
    k.addCom(73, 34, 51);
    k.locateSquad();
    k.removeCom();
    k.removeCom();
    return 0;
}
*/
