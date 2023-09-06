//
// ITable.hh for  in /home/fus/taff/cpp_santa/ex4
//
// Made by Gaspard Thirion
// Login   <thirio_b@epitech.net>
//
// Started on  Fri Jan 13 23:21:30 2017 Gaspard Thirion
// Last update Sun Jan 15 04:40:53 2017 baris_f
//

#ifndef ITABLE
#define ITABLE

#include <iostream>

class ITable
{
public:
  virtual ~ITable(){};
  virtual Object*	Take(std::string)	= 0;
  virtual std::string*	Look()			= 0;
  virtual void		Put(Object*)		= 0;
  virtual void		addToy()		= 0;
};

#endif
