//
// Object.hh for  in /home/grandm_a/cpp_d10/cpp_santa/ex1
//
// Made by grandm_a
// Login   <corentin.grandmaire@epitech.eu>
//
// Started on  Sat Jan 14 00:27:47 2017 grandm_a
// Last update Sat Jan 14 22:22:07 2017 Duval Lucas
//

#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <iostream>

class Object
{

public:
  Object(std::string const& name, std::string type, int wrap_lvl = 0, bool wraped = false);
  Object(Object const& new_obj);
  ~Object();

  Object& operator=(Object const& cpy_obj);

  std::string const&	getName() const;
  std::string const&	getType() const;
  int			getWrapLvl() const;
  bool			getWrapped() const;
  bool			getTaken() const;

  void			isTaken();
  void			setWrapped(bool wrap);


protected :
  std::string	_name;
  std::string	_type;
  int		_wrapLvl;
  bool		_wrapped;
  bool		_isTaken;
};

std::ostream &operator<<(std::ostream &, Object const &);

#endif
