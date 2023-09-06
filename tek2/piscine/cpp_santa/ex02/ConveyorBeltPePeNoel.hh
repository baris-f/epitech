#ifndef conveyorbelt_hh
#define conveyorbelt_hh

#include <iostream>

#include <ctime>
#include <cstdlib>

#include "Object.hh"
#include "IConveyorBelt.hh"
#include "Box.hh"
#include "GiftPaper.hh"

class ConveyorBeltPePeNoel : public IConveyorBelt {
public:
  ConveyorBeltPePeNoel();
  ~ConveyorBeltPePeNoel();

  void in();
  void put(Object*);
  void out();
  Object *take();
  std::string look();

private:
  Object* _object;
  bool _lastIsBox;

};

#endif
