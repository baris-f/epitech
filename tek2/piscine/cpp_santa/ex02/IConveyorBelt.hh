#ifndef iconveyorbelt_hh
#define iconveyorbelt_hh

#include <string>

#include "Object.hh"

class IConveyorBelt
{
public:
  virtual ~IConveyorBelt() {}
  virtual void in() = 0;
  virtual void put(Object*) = 0;
  virtual void out() = 0;
  virtual std::string look() = 0;
};

#endif
