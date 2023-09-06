#ifndef teddy_h
#define teddy_h

#include <iostream>
#include <string>
#include "Toy.hh"

class Teddy : virtual public Object, public Toy
{

public:
  Teddy(std::string const& name);
  ~Teddy();

  void isTaken();

};

#endif
