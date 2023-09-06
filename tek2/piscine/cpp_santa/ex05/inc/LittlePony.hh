#ifndef pony_h
#define pony_h

#include <iostream>
#include <string>
#include "Toy.hh"

class LittlePony : public Toy
{
  
public:
  LittlePony(std::string const& name);
  ~LittlePony();
  
  void isTaken();
  
};

#endif
