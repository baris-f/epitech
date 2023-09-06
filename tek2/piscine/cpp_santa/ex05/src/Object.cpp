//
// Object.cpp for  in /home/grandm_a/cpp_d10/cpp_santa/ex1
//
// Made by grandm_a
// Login   <corentin.grandmaire@epitech.eu>
//
// Started on  Sat Jan 14 00:27:51 2017 grandm_a
// Last update Sat Jan 14 22:35:52 2017 Duval Lucas
//

#include "Object.hh"

Object::Object(std::string const& name, std::string type, int wrap_lvl, bool wrapped) :
  _name(name), _type(type), _wrapLvl(wrap_lvl), _wrapped(wrapped), _isTaken(false)
{

}

Object::Object(Object const& new_obj) :
  _name(new_obj._name), _type(new_obj._type), _wrapLvl(new_obj._wrapLvl), _wrapped(new_obj._wrapped), _isTaken(new_obj._isTaken)
{

}

Object::~Object()
{
}

std::string const&	Object::getName() const { return (_name); }

std::string const&	Object::getType() const { return (_type); }

int			Object::getWrapLvl() const { return (_wrapLvl); }

bool			Object::getWrapped() const { return (_wrapped); }

bool			Object::getTaken() const { return (_isTaken); }


void			Object::isTaken() { _isTaken = true; }

void			Object::setWrapped(bool wrap) { _wrapped = wrap; }

Object&			Object::operator=(Object const& cpy_obj)
{
  _name = cpy_obj.getName();
  _type = cpy_obj.getType();
  _wrapLvl = cpy_obj.getWrapLvl();
  _wrapped = cpy_obj.getWrapped();
  _isTaken = cpy_obj.getTaken();
  return (*this);
}

std::ostream &operator<<(std::ostream &os, Object const &o){
  os << "It's a "<< o.getType() << " named " << o.getName() << std::endl;
  return os;
}
