//
// TablePePeNoel.hh for  in /home/fus/taff/cpp_santa/ex4/inc
//
// Made by Gaspard Thirion
// Login   <thirio_b@epitech.net>
//
// Started on  Fri Jan 13 23:46:49 2017 Gaspard Thirion
// Last update Sun Jan 15 05:02:04 2017 baris_f
//

#ifndef TABLEPEPE
#define TABLEPEPE

#include "Object.hh"
#include "ITable.hh"

class maillon
{
public:
  maillon(Object*, maillon*);
  ~maillon(){};
private:
  maillon*	_next;
  Object*	_object;
public:
  Object*	getObject() const;
  maillon*	getNext() const;
  void		setNext(maillon*);
};

std::ostream&	operator<<(std::ostream&, maillon&);

class TablePePeNoel : public ITable
{
public:
  TablePePeNoel();
  TablePePeNoel(const TablePePeNoel&);
  ~TablePePeNoel(){};
private:
  size_t	_size;
  maillon*	_list;
public:
  Object*	Take(std::string);
  std::string*	Look();
  void		Put(Object*);
  int		getSize();
  void		addToy();
};

#endif
