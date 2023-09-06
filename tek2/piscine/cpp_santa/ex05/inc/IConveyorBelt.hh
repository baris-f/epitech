#ifndef iconveyorbelt_hh
#define iconveyorbelt_hh

#include <string>

#include "Wrap.hh"

class IConveyorBelt
{
public:
  virtual ~IConveyorBelt() {}
  virtual void in() = 0;
  virtual void put(Wrap*) = 0;
  virtual void out() = 0;
  virtual std::string look() = 0;
};

#endif
