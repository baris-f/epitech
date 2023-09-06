//
// KoalaBot.cpp for koala in /home/baris_f/rendu/tek2/cpp_d07a/ex01
//
// Made by baris_f
// Login   <florent.baris@epitech.eu>
//
// Started on  Tue Jan 10 18:37:14 2017 baris_f
// Last update Tue Jan 10 23:14:55 2017 baris_f
//

#include "KoalaBot.h"

KoalaBot::KoalaBot(std::string serial)
{
  _serial = serial;
}

KoalaBot::~KoalaBot(){

}

void	KoalaBot::setParts(const Arms& arm){
  _arm = arm;
}

void	KoalaBot::setParts(const Legs& leg){
  _leg = leg;
}

void	KoalaBot::setParts(const Head& head){
  _head = head;
}

void  KoalaBot::swapParts(Arms& arm)
{
  Arms tmp;

  tmp = _arm;
  _arm = arm;
  arm = tmp;
}

void  KoalaBot::swapParts(Legs& leg)
{
  Legs tmp;

  tmp = _leg;
  _leg = leg;
  leg = tmp;
}

void  KoalaBot::swapParts(Head& head)
{
  Head tmp;

  tmp = _head;
  _head = head;
  head = tmp;
}

void	KoalaBot::informations() const
{
  std::cout << "[KoalaBot] " << _serial << std::endl;
  _arm.informations();
  _leg.informations();
  _head.informations();
}

bool	KoalaBot::status() const
{
  if (_arm.isFunctionnal() && _leg.isFunctionnal() && _head.isFunctionnal())
    return (true);
  return (false);
}

/*
int main()
{
  KoalaBot kb;
  Arms  a("test", false);

  kb.informations();
  std::cout << std::boolalpha << kb.status() << std::endl;
  kb.swapParts(a);
  kb.informations();
  std::cout << std::boolalpha << kb.status() << std::endl;

  kb.swapParts(a);
  kb.informations();
  std::cout << std::boolalpha << kb.status() << std::endl;
  return 0;
}
  */
